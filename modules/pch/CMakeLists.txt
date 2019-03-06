message(STATUS "Precompiled header module")

file(GLOB_RECURSE header_files "*.h")
file(GLOB_RECURSE source_files "*.cpp")

add_library(pch_library ${header_files} ${source_files})
target_include_directories(pch_library PUBLIC ${MAIN_DIR})
if (MSVC)
    add_precompiled_header(example_main include/precomp.h FORCEINCLUDE SOURCE_CXX source/precomp.cpp)
    add_precompiled_header(example_bio include/precomp.h FORCEINCLUDE SOURCE_CXX source/precomp.cpp)
    add_precompiled_header(example_pipelines include/precomp.h FORCEINCLUDE SOURCE_CXX source/precomp.cpp)
    add_precompiled_header(Test_Target include/precomp.h FORCEINCLUDE SOURCE_CXX source/precomp.cpp)
    add_precompiled_header(Benchmark_Target include/precomp.h FORCEINCLUDE SOURCE_CXX source/precomp.cpp)
endif()