// Tutorial does not provide CMAKE, I copied this from Github BT page, I only guess we have to import the my_tree.xml here ?

cmake_minimum_required(VERSION 3.5)

project(hello_BT)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(BehaviorTreeV3)

add_executable(${PROJECT_NAME} "t01_build_your_first_tree.cpp")
target_link_libraries(${PROJECT_NAME} BT::behaviortree_cpp_v3)
