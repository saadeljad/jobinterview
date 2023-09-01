# CMake generated Testfile for 
# Source directory: /home/sxxxd/Downloads/amr_example_small/ros_cpp
# Build directory: /home/sxxxd/Downloads/amr_example_small/build/ros_cpp
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(ros_cpp_my_test "/usr/bin/python3" "-u" "/opt/ros/foxy/share/ament_cmake_test/cmake/run_test.py" "/home/sxxxd/Downloads/amr_example_small/build/ros_cpp/test_results/ros_cpp/ros_cpp_my_test.gtest.xml" "--package-name" "ros_cpp" "--output-file" "/home/sxxxd/Downloads/amr_example_small/build/ros_cpp/ament_cmake_gtest/ros_cpp_my_test.txt" "--command" "/home/sxxxd/Downloads/amr_example_small/build/ros_cpp/ros_cpp_my_test" "--gtest_output=xml:/home/sxxxd/Downloads/amr_example_small/build/ros_cpp/test_results/ros_cpp/ros_cpp_my_test.gtest.xml")
set_tests_properties(ros_cpp_my_test PROPERTIES  LABELS "gtest" REQUIRED_FILES "/home/sxxxd/Downloads/amr_example_small/build/ros_cpp/ros_cpp_my_test" TIMEOUT "60" WORKING_DIRECTORY "/home/sxxxd/Downloads/amr_example_small/build/ros_cpp" _BACKTRACE_TRIPLES "/opt/ros/foxy/share/ament_cmake_test/cmake/ament_add_test.cmake;118;add_test;/opt/ros/foxy/share/ament_cmake_gtest/cmake/ament_add_gtest_test.cmake;86;ament_add_test;/opt/ros/foxy/share/ament_cmake_gtest/cmake/ament_add_gtest.cmake;93;ament_add_gtest_test;/home/sxxxd/Downloads/amr_example_small/ros_cpp/CMakeLists.txt;70;ament_add_gtest;/home/sxxxd/Downloads/amr_example_small/ros_cpp/CMakeLists.txt;0;")
subdirs("gtest")
