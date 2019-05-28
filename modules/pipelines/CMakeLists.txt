message(STATUS "Pipelines module")

file(GLOB_RECURSE header_files "*.h")
file(GLOB_RECURSE source_files "*.cpp")

add_library(pipelines_library ${header_files} ${source_files})
target_link_libraries(pipelines_library common_library)
target_link_libraries(pipelines_library yaml)
