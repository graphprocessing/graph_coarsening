message(STATUS "Application module")
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} common_library)
target_link_libraries(${PROJECT_NAME} pch_library)
