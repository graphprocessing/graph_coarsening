message(STATUS "-- Example pipelines")

project(example_pipelines)
add_executable(${PROJECT_NAME} pipelines.cpp)
if ( CMAKE_COMPILER_IS_GNUCXX )
    add_precompiled_header(${PROJECT_NAME} ../../modules/pch/include/precomp.h SOURCE_CXX ../../modules/pch/source/precomp.cpp FORCEINCLUDE)
endif ( CMAKE_COMPILER_IS_GNUCXX )
target_link_libraries(${PROJECT_NAME} ${libs})
include_directories(${MAIN_DIR})
