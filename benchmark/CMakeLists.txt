message(STATUS "Benchmark module")

file(GLOB_RECURSE source_files "*.cpp")

project(Benchmark_Target)
###############################################################
## BenchmarkTest
###############################################################
include(ExternalProject)
ExternalProject_Add(benchmark_test
    GIT_REPOSITORY https://github.com/google/benchmark
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/benchmark_test
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
    CMAKE_ARGS -DCMAKE_BUILD_TYPE=RELEASE
    CMAKE_ARGS -DBENCHMARK_DOWNLOAD_DEPENDENCIES=ON
)
ExternalProject_Get_Property(benchmark_test install_dir)
include_directories(${install_dir}/include)
###############################################################

add_dependencies(benchmark_test gtest)

include_directories(include)
add_executable(${PROJECT_NAME} ${source_files})

target_link_libraries(${PROJECT_NAME} data_structures_library)
target_link_libraries(${PROJECT_NAME} generator_library)
target_link_libraries(${PROJECT_NAME} algorithms_library)
target_link_libraries(${PROJECT_NAME} common_library)

add_dependencies(${PROJECT_NAME} benchmark_test)
target_link_libraries(${PROJECT_NAME} ${install_dir}/lib/libbenchmark.a)
target_link_libraries(${PROJECT_NAME} ${install_dir}/lib/libbenchmark_main.a)
