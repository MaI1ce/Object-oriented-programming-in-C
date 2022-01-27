# /study/ooc/lib/libNew
cmake_minimum_required(VERSION 3.18)

#can be changed
project(OOP_in_C)

set(SOURCES new.c)

set(HEADRES new.h class.h cldef.h)

add_library(libNew STATIC ${SOURCES})
target_include_directories(libNew PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
