message(STATUS "Precompiled header module")

file(GLOB_RECURSE header_files "*.h")
file(GLOB_RECURSE source_files "*.cpp")

add_library(pch_library ${header_files} ${source_files})
target_include_directories(pch_library PUBLIC ${MAIN_DIR})

find_package(Git REQUIRED)
execute_process(COMMAND git clone https://github.com/larsch/cmake-precompiled-header.git
                    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
include(${CMAKE_CURRENT_BINARY_DIR}/cmake-precompiled-header/PrecompiledHeader.cmake)