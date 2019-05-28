message(STATUS "General purpose module")

file(GLOB_RECURSE header_files "*.h")
file(GLOB_RECURSE source_files "*.cpp")

add_library(common_library ${header_files} ${source_files})
