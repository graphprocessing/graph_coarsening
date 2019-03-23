message(STATUS "Tests module")

file(GLOB_RECURSE source_files "*.cpp")

project(test_target)

add_executable(${PROJECT_NAME} ${source_files})
if ( CMAKE_COMPILER_IS_GNUCXX )
    add_precompiled_header(${PROJECT_NAME} ../modules/pch/include/precomp.h SOURCE_CXX ../modules/pch/source/precomp.cpp FORCEINCLUDE)
endif ( CMAKE_COMPILER_IS_GNUCXX )
target_link_libraries( ${PROJECT_NAME} ${libs} )
target_link_libraries( ${PROJECT_NAME} gtest gtest_main )

enable_testing()
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
include_directories(${MAIN_DIR})
