cmake_minimum_required(VERSION 3.20)
project(my_cpp_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
find_package(rclcpp REQUIRED)

add_executable(my_first_node src/my_first_node.cpp)
target_link_libraries(my_first_node PUBLIC rclcpp::rclcpp)

install(TARGETS
  my_first_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
