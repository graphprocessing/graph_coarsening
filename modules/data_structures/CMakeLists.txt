message(STATUS "Data structures module")

file(GLOB_RECURSE header_files "*.h")
file(GLOB_RECURSE source_files "*.cpp")

add_library(data_structures_library ${header_files} ${source_files})
include_directories(${MAIN_DIR})
