cmake_minimum_required( VERSION 2.8 )

set(libs common_library pipelines_library yaml)

option( BENCHMARK_ENABLE_GTEST_TESTS "" OFF )
if( WIN32 )
    option( gtest_force_shared_crt "" TRUE )
endif( WIN32 )

add_subdirectory( 3rdparty/googletest )
add_subdirectory( 3rdparty/benchmark )
add_subdirectory( 3rdparty/libyaml )

include( cmake/Configure.cmake )
include( cmake/PrecompiledHeader.cmake )

add_subdirectory( modules )
add_subdirectory( tests )
add_subdirectory( benchmark )
add_subdirectory( samples )

# if (MSVC)
#     add_precompiled_header(pch modules/pch/pch.h SOURCE_CXX modules/pch/pch.cpp FORCEINCLUDE)
# endif(MSVC)
