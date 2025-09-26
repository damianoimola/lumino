cmake_minimum_required(VERSION 3.16)
project(lumino)

set(CMAKE_CXX_STANDARD 20)

add_executable(lumino main.cpp)

# build /lib
add_subdirectory(lib)
target_link_libraries(lumino PRIVATE lumino_lib)

# build Eigen
find_package(Eigen3 REQUIRED)
target_link_libraries(lumino PRIVATE Eigen3::Eigen)

# build BehaviorTree.CPP
add_subdirectory(third_party/BehaviorTree.CPP)
target_link_libraries(lumino PRIVATE BT::behaviortree_cpp)



# https://stackoverflow.com/a/2360780