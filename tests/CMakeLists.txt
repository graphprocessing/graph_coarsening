message(STATUS "Tests module")

project(Test_Target)
include_directories(include)
add_executable(${PROJECT_NAME} source/run_tests.cpp)
target_link_libraries(${PROJECT_NAME} data_structures_library)
target_link_libraries(${PROJECT_NAME} GTest)
