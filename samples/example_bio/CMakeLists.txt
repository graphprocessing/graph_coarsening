message(STATUS "-- Example bio")

project(example_bio)
add_executable(${PROJECT_NAME} bio.cpp)
target_link_libraries(${PROJECT_NAME} common_library)
include_directories(${MAIN_DIR})
