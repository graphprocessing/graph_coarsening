// Copyright [year] <Copyright Owner>
#ifndef MODULES_GENERATORS_INCLUDE_GENERATOR_H_
#define MODULES_GENERATORS_INCLUDE_GENERATOR_H_
#include "../../data_structures/include/graph.h"
#include "../../data_structures/include/csr.h"
#include "../../data_structures/include/adjacency_list.h"

CSR washington_test(int n, bool weighted = false);
AL zadeh_test(int n, bool weighted = false);

#endif  // MODULES_GENERATORS_INCLUDE_GENERATOR_H_
