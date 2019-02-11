message( STATUS "Benchmark module" )

file( GLOB_RECURSE source_files "*.cpp" )

project( Benchmark_Target )

add_executable( ${PROJECT_NAME} ${source_files} )

set(GRAPH_LIBRARIES_BENCHMARK benchmark benchmark_main common_library)
target_link_libraries( ${PROJECT_NAME} ${GRAPH_LIBRARIES_BENCHMARK} )

include_directories(${MAIN_DIR})
