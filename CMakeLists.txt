cmake_minimum_required(VERSION 3.28)
project(PartChecker VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#find OpenCV package
find_package(OpenCV REQUIRED)

#includ libraries from OpenCV
include_directories(${OpenCv_INCLUDE_DIRS})

#Create executable
add_executable(PartChecker main.cpp ./Camera/Camera.hpp ./Camera/Camera.cpp ./Algorithms/Algorithms.hpp ./Algorithms/Algorithms.cpp)

#link OpenCV libraries
target_link_libraries(PartChecker ${OpenCV_LIBS})