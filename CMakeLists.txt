cmake_minimum_required(VERSION 3.16)   # bump version, 4.0 isn’t valid!
project(lumino)

set(CMAKE_CXX_STANDARD 20)

add_executable(lumino test_behavior_tree.cpp)

find_package(Eigen3 REQUIRED)
target_link_libraries(lumino PRIVATE Eigen3::Eigen)

# Build BehaviorTree.CPP as part of your project
add_subdirectory(third_party/BehaviorTree.CPP)
target_link_libraries(lumino PRIVATE BT::behaviortree_cpp)
