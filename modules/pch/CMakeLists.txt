message(STATUS "Generator module")

file(GLOB_RECURSE header_files "*.h")
file(GLOB_RECURSE source_files "*.cpp")

add_library(pch_library ${header_files} ${source_files})
target_include_directories(pch_library PUBLIC ${MAIN_DIR})
