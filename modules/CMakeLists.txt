project(Graph_Partition)

add_subdirectory(common)
add_subdirectory(pch)
# if (NOT MSVC)
#     add_precompiled_header(${PROJECT_NAME} pch/include/precomp.h SOURCE_CXX pch/source/precomp.cpp FORCEINCLUDE)
# endif()

include_directories(${MAIN_DIR})
