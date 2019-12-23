cmake_minimum_required(VERSION 2.8.9)
set(CMAKE_CXX_STANDARD 17)
project(CppCommons)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_library(cpp_common STATIC ${SOURCES})

if(MSVC)
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()
