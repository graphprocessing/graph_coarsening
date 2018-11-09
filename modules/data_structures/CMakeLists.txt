message(STATUS "Data structures module")
set(header_files include/graph.h include/adjacency_list.h include/csr.h include/jds.h)
set(source_files source/graph.cpp source/adjacency_list.cpp source/csr.cpp source/jds.cpp)
add_library(data_structures_library ${header_files} ${source_files})
