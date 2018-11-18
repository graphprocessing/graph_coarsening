message(STATUS "Tests module")

file(GLOB_RECURSE source_files "*.cpp")

project(Test_Target)
include_directories(include)
add_executable(${PROJECT_NAME} ${source_files})
target_link_libraries(${PROJECT_NAME} data_structures_library)
target_link_libraries(${PROJECT_NAME} generator_library)
target_link_libraries(${PROJECT_NAME} algorithms_library)
target_link_libraries(${PROJECT_NAME} common_library)
target_link_libraries(${PROJECT_NAME} GTest)
