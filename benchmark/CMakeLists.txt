message( STATUS "Benchmark module" )

file( GLOB_RECURSE source_files "*.cpp" )

project( Benchmark_Target )

set( BENCHMARK_ENABLE_GTEST_TESTS OFF PARENT_SCOPE )
set (CMAKE_BUILD_TYPE RELEASE )

configure_file( CMakeLists.txt.in google-benchmark-download/CMakeLists.txt )
execute_process( COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/google-benchmark-download )
if(result)
    message( FATAL_ERROR "CMake step for google-benchmark failed: ${result}" )
endif()
execute_process( COMMAND ${CMAKE_COMMAND} --build .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/google-benchmark-download )
if(result)
    message( FATAL_ERROR "Build step for google-benchmark failed: ${result}" )
endif()

add_subdirectory( ${CMAKE_CURRENT_BINARY_DIR}/google-benchmark-src
                  ${CMAKE_CURRENT_BINARY_DIR}/google-benchmark-build
                  EXCLUDE_FROM_ALL )
add_executable( ${PROJECT_NAME} ${source_files} )

target_link_libraries( ${PROJECT_NAME} data_structures_library )
target_link_libraries( ${PROJECT_NAME} generator_library )
target_link_libraries( ${PROJECT_NAME} algorithms_library )
target_link_libraries( ${PROJECT_NAME} common_library )
target_link_libraries( ${PROJECT_NAME} benchmark_main )
target_link_libraries( ${PROJECT_NAME} benchmark )
