cmake_minimum_required(VERSION 3.18)

project(
  funwithloggers
)

set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")
set(CMAKE_CXX_STANDARD 20)

add_library(
  lib
)

target_sources(
  lib
  PRIVATE   src/LogStream.cpp
  PUBLIC    src/Logger.hpp
            src/LogStream.hpp
)

target_include_directories(
  lib
  PUBLIC src/
)

add_executable(
  main
)

target_sources(
  main
  PRIVATE test/main.cpp
)

target_link_libraries(
  main
  PRIVATE lib
)
