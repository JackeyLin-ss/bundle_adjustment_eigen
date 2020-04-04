cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(bundle_adjustment_eigen)

set(CMAKE_BUILD_TYPE Release)
message("Build type: " ${CMAKE_BUILD_TYPE})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

find_package(Eigen REQUIRED)
include_directories(${EIGEN_INCLUDE_DIR}
    ${PROJECT_SOURCE_DIR}/include)


add_executable(test_solver
    src/test_solver.cc
)


add_executable(test_ba
    src/bundle_adjustment.cc)

