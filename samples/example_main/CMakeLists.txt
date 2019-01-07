message(STATUS "-- Example main")

project(example_main)
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} common_library)
include_directories(${MAIN_DIR})
