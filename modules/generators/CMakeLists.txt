message(STATUS "Generator module")

file(GLOB_RECURSE header_files "*.h")
file(GLOB_RECURSE source_files "*.cpp")

add_library(generator_library ${header_files} ${source_files})
include_directories(${MAIN_DIR})
