cmake_minimum_required(VERSION 3.5)

project(unix_domain_socket LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(unix_domain_socket main.cpp)
