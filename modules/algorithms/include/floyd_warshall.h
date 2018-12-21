// Copyright [year] <Copyright Owner>
#ifndef MODULES_ALGORITHMS_INCLUDE_FLOYD_WARSHALL_H_
#define MODULES_ALGORITHMS_INCLUDE_FLOYD_WARSHALL_H_
#include "../../pch/include/precomp.h"

void floyd_warshall(std::vector <std::vector <int>>* matrix,
                            const CSR& graph);

#endif  // MODULES_ALGORITHMS_INCLUDE_FLOYD_WARSHALL_H_
