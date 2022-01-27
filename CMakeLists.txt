# /study/ooc/
cmake_minimum_required(VERSION 3.18)

project(OOP_in_C)

set(SOURCES main2.cpp MyString.c)

add_subdirectory(lib)
add_subdirectory(tests)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} libNew)

#---------------------------------------


