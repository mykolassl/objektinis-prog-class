#cmake_minimum_required(VERSION 3.25)
#project(test)
#
#include_directories(../libs)
#file(GLOB SOURCES "../src/*.cpp")
#file(GLOB HEADERS "../libs/*.h")
#add_executable(test ${SOURCES} ${HEADERS} test.cpp)
#add_test(NAME test COMMAND test)
#target_link_libraries(test PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)


set(BINARY ${CMAKE_PROJECT_NAME}_test)
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES false *.h *.cpp)
set(SOURCES ${SOURCES})
add_executable(${BINARY} ${SOURCES})
add_test(NAME ${BINARY} COMMAND ${BINARY})
target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)
