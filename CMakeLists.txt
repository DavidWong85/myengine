cmake_minimum_required(VERSION 2.6)
project(MYENGINE)

include_directories(
   src
)

add_library(myengine
   src/myengine/Core.h
   src/myengine/Core.cpp
)

add_executable(demo
   src/demo/main.cpp
)

target_link_libraries(demo myengine)