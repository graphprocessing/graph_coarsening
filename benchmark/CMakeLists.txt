message( STATUS "Benchmark module" )

file( GLOB_RECURSE source_files "*.cpp" )

project( benchmark_target )

add_executable( ${PROJECT_NAME} ${source_files} )
if ( CMAKE_COMPILER_IS_GNUCXX )
    add_precompiled_header(${PROJECT_NAME} ../modules/pch/include/precomp.h SOURCE_CXX ../modules/pch/source/precomp.cpp FORCEINCLUDE)
endif ( CMAKE_COMPILER_IS_GNUCXX )
set(GRAPH_LIBRARIES_BENCHMARK benchmark benchmark_main ${libs})
target_link_libraries( ${PROJECT_NAME} ${GRAPH_LIBRARIES_BENCHMARK} )

include_directories(${MAIN_DIR})
