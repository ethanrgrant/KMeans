cmake_minimum_required(VERSION 3.7)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp point.cpp point.h kMeans.cpp kMeans.h cluster.cpp cluster.h)
add_executable(untitled ${SOURCE_FILES})