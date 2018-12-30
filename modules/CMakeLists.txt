project(Graph_Partition)

add_subdirectory(common)
add_subdirectory(application)
add_subdirectory(pch)
if (NOT MSVC)
    add_precompiled_header(${PROJECT_NAME} ../modules/pch/include/pch.h SOURCE_CXX modules/pch/source/pch.cpp FORCEINCLUDE)
endif()

include_directories(${MAIN_DIR})