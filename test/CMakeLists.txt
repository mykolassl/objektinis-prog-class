
set(BINARY ${CMAKE_PROJECT_NAME}_test)
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES false *.h *.cpp)
set(SOURCES ${SOURCES})
add_executable(${BINARY} ${SOURCES})
add_test(NAME ${BINARY} COMMAND ${BINARY})
target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)
