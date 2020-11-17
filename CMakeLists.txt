cmake_minimum_required(VERSION 3.14)
project(CMakeDemo)
set(CMAKE_CXX_STANDARD 17)

message("eigen INC : ${PROJECT_SOURCE_DIR}/ThirdParty/eigen")
set(EIGEN_INC "${PROJECT_SOURCE_DIR}/ThirdParty/eigen")

add_executable(decompositions decompositions.cpp)
target_include_directories(decompositions PRIVATE ${EIGEN_INC})

add_executable(least_squares least_squares.cpp)
target_include_directories(least_squares PRIVATE ${EIGEN_INC})
