cmake_minimum_required(VERSION 3.0.0)
project(inference VERSION 0.1.0 LANGUAGES C CXX)

include_directories(fastforest/include)
link_directories(fastforest/lib)

add_executable(fastforest.exe main.cpp)
target_link_libraries(fastforest.exe libfastforest.so)


