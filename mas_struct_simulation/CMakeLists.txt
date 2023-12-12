cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME mass_struct_simulation)
project(${PROJECT_NAME})

add_library(mass_struct ./class_Subbody.cpp ./class_Subbody.h ./mas_struct.h ./masstruct.cpp)
add_executable(program ./Source.cpp)
target_link_libraries(program mass_struct)
