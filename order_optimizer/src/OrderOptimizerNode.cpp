#include "OrderOptimizerNode.h"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "rclcpp/rclcpp.hpp"
#include "yaml-cpp/yaml.h"

#include <memory>
#include <tiff.h>

//------------------------------------------------------------------------------------------------------------------------------------
OrderOptimizerNode::OrderOptimizerNode() : Node("OrderOptimizer")
{
  // file for test purpose
  file = "output_";
  file += std::to_string((rand() % 10 + 1));
  outputFile.open(file + ".txt");
  
  // TODO: get Parameter + create Publisher + Subscriber
  
  currentPositionSub_ = this->create_subscription<geometry_msgs/PostStamped>(
      "currentPosition’", 10, std::bind(&OrderOptimizerNode::msgCurrentPos, this, _1));
}

//------------------------------------------------------------------------------------------------------------------------------------
void OrderOptimizerNode::msgCurrentPos(geometry_msgs::msg::PoseStamped::SharedPtr msg)
{
  //  RCLCPP_INFO(this->get_logger(), "I heard current position mgs");
  current_pose = msg;
}

//------------------------------------------------------------------------------------------------------------------------------------
bool compare(std::pair<float, Part> p1, std::pair<float, Part> p2) { return p1.first < p2.first; }

//------------------------------------------------------------------------------------------------------------------------------------
void OrderOptimizerNode::msgNextOrder(msg_package::msg::Order::SharedPtr msg)
{
  path_ = this->get_parameter("path").get_value<std::string>();
  //  RCLCPP_INFO(this->get_logger(), "I heard nextOrder msg of order: '%d' ( '%s' )",msg->order_id,
  //  msg->description.c_str());
  if (!fs::is_directory(path_)) {
    std::cout << "[ERROR]: Absolute path is not a directory!" << std::endl;
    outputFile << "[ERROR]: Absolute path is not a directory!\n";
    return;
  } else if (!current_pose) {
    std::cout << "[ERROR]: AMR current position not Known!" << std::endl;
    outputFile << "[ERROR]: AMR current position not Known!\n";
    return;
  }

  uint32 order_id = msg->order_id;
  bool found = false;
  OrderDetails details_;
  for (auto &folder : std::filesystem::recursive_directory_iterator(path_)) {
    if (folder.is_directory() && (folder.path().filename().string()).compare("orders") == 0) {
      std::vector<std::string> files_;
      std::list<std::thread> threads_;

      for (auto &file : std::filesystem::directory_iterator(folder.path())) {
        // TODO: parse files using one of the parser methods
      }
	  
      // std::cout << "before threads" << std::endl;

      for (std::thread &thread : threads_) {
        if (thread.joinable())
          thread.join();
      }
      // std::cout << "threads" << std::endl;
      if (!found) {
        std::cout << "[ERROR]: Order " << order_id << " not found!" << std::endl;
        outputFile << "[ERROR]: Order " << order_id << " not found!\n";
        return;
      }
    } else if (folder.is_directory() && (folder.path().filename().string()).compare("configuration") == 0
               && !configuration_already) {
      for (auto &file : std::filesystem::directory_iterator(folder.path())) {
        parseConfFile(file.path());
      }
    } else if (found && configuration_already)
      break;
  }

  if (!found || !configuration_already) {
    std::cout << "[ERROR]: orders/configuration folder not found!" << std::endl;
    outputFile << "[ERROR]: orders/configuration folder not found!";
    return;
  }

  std::vector<std::pair<float, Part>> path_vec = FindShortestPath(details_);
  PathOutput(msg, path_vec, details_);
  PublishMarkerArray(path_vec);
}

//------------------------------------------------------------------------------------------------------------------------------------
void OrderOptimizerNode::PathOutput(msg_package::msg::Order::SharedPtr msg, std::vector<std::pair<float, Part>> vector,
                                    OrderDetails details_)
{

  std::cout << "Working on order " << msg->order_id << " (" << msg->description << ")" << std::endl;
  outputFile << "Working on order " << msg->order_id << " (" << msg->description << ")" << std::endl;

  size_t i = 0;
  for (; i < vector.size(); i++) {

    std::cout << i << ". Fetching part '" << vector[i].second.part_name << "' for product '"
              << vector[i].second.parent_product << "' at x: " << vector[i].second.cx << ", y: " << vector[i].second.cy
              << std::endl;

    outputFile << i << ". Fetching part '" << vector[i].second.part_name << "' for product '"
               << vector[i].second.parent_product << "' at x: " << vector[i].second.cx << ", y: " << vector[i].second.cy
               << std::endl;
  }

  std::cout << i << ". Delivering to destination x:" << details_.cx << ", y: " << details_.cy << std::endl;
  outputFile << i << ". Delivering to destination x:" << details_.cx << ", y: " << details_.cy << std::endl;
}

//------------------------------------------------------------------------------------------------------------------------------------
std::vector<std::pair<float, Part>> OrderOptimizerNode::FindShortestPath(OrderDetails details_)
{
  // TODO: Implement me
}

//------------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------------------------
void OrderOptimizerNode::PublishMarkerArray(std::vector<std::pair<float, Part>> path_vec)
{
  visualization_msgs::msg::MarkerArray markerArray;
  auto aMR_marker = AMRMarker();
  markerArray.markers.push_back(aMR_marker);

  for (auto it = path_vec.begin(); it != path_vec.end(); ++it) {
    auto pickupMarker = Pickup(*it);
    markerArray.markers.push_back(pickupMarker);
  }
}

//------------------------------------------------------------------------------------------------------------------------------------
visualization_msgs::msg::Marker OrderOptimizerNode::AMRMarker()
{
  visualization_msgs::msg::Marker marker;
  marker.ns = "AMR";
  marker.header.frame_id = "order_path";
  marker.type = visualization_msgs::msg::Marker::CUBE;
  if (current_pose) {
    marker.pose.position.x = current_pose->pose.position.x;
    marker.pose.position.y = current_pose->pose.position.y;
  }
  marker.scale.x = 1;
  marker.scale.y = 0.1;
  marker.scale.z = 0.1;
  marker.action = visualization_msgs::msg::Marker::ADD;
  marker.color.a = 1.0;
  marker.color.r = 0.0;
  marker.color.g = 1.0;
  marker.color.b = 0.0;
  return marker;
}

//------------------------------------------------------------------------------------------------------------------------------------
visualization_msgs::msg::Marker OrderOptimizerNode::Pickup(std::pair<float, Part> pair)
{
  visualization_msgs::msg::Marker marker;
  marker.ns = pair.second.parent_product + " " + pair.second.part_name;
  marker.header.frame_id = "order_path";
  marker.header.stamp = this->now();
  marker.type = visualization_msgs::msg::Marker::CYLINDER;
  marker.pose.position.x = pair.second.cx;
  marker.pose.position.y = pair.second.cy;
  marker.scale.x = 1;
  marker.scale.y = 0.1;
  marker.scale.z = 0.1;
  marker.action = 0;
  marker.color.a = 1.0;
  marker.color.r = 1.0;
  marker.color.g = 0.0;
  marker.color.b = 0.0;
  return marker;
}

//------------------------------------------------------------------------------------------------------------------------------------
float OrderOptimizerNode::distance(float x1, float y1, float x2, float y2)
{
  auto x = pow(x2 - x1, 2);
  auto y = pow(y2 - y1, 2);
  return sqrt(x + y * 1.0);
}

//------------------------------------------------------------------------------------------------------------------------------------
void OrderOptimizerNode::parseConfFile(fs::path file)
{
  // std::cout << "working with file " << file.string() << std::endl;

  YAML::Node config = YAML::LoadFile(file.string());
  for (size_t i = 0; i < config.size(); ++i) {
    int product_id = config[i]["id"].as<int>();
    ProductDetails product_;
    product_.product_name = config[i]["product"].as<std::string>();
    for (size_t j = 0; j < config[i]["parts"].size(); ++j) {
      auto part_it = config[i]["parts"][j];

      Part part_;
      part_.part_name = part_it["part"].as<std::string>();
      part_.cx = part_it["cx"].as<float>();
      part_.cy = part_it["cy"].as<float>();
      part_.parent_product = product_.product_name;

      product_.parts.push_back(part_);
    }
    products.insert({product_id, product_});
  }

  configuration_already = true;
}

//------------------------------------------------------------------------------------------------------------------------------------
void OrderOptimizerNode::parseOrderFile(fs::path file, uint32 order_id, bool &found, OrderDetails *details,
                                        std::vector<std::string> &pr)
{
  // std::cout << "I am thread " << std::this_thread::get_id() << " working with file " << file.string() << std::endl;

  std::vector<std::string> &pr_ = const_cast<std::vector<std::string> &>(pr);
  YAML::Node config = YAML::LoadFile(file.string());
  for (size_t i = 0; i < config.size(); ++i) {
    if (config[i]["order"].as<uint32>() == order_id) {
      found = true;
      details->order_id = order_id;
      details->cx = config[i]["cx"].as<float>();
      details->cy = config[i]["cy"].as<float>();

      for (size_t j = 0; j < config[i]["products"].size(); ++j) {
        pr_.push_back(config[i]["products"][j].as<std::string>());
      }
      break;
    }
  }
}

//------------------------------------------------------------------------------------------------------------------------------------
