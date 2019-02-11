message(STATUS "Tests module")

file(GLOB_RECURSE source_files "*.cpp")

project(Test_Target)

add_executable(${PROJECT_NAME} ${source_files})

target_link_libraries( ${PROJECT_NAME} common_library )
target_link_libraries( ${PROJECT_NAME} gtest gtest_main )

enable_testing()
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
include_directories(${MAIN_DIR})
