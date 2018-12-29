// Copyright [year] <Copyright Owner>
#ifndef MODULES_ALGORITHMS_INCLUDE_FIND_BRIDGES_H_
#define MODULES_ALGORITHMS_INCLUDE_FIND_BRIDGES_H_
#include "../../pch/include/precomp.h"

template <typename WeightType>
void find_bridges(std::set <std::pair <int, int>>* bridges, const CSR<WeightType>& graph);

template <typename WeightType>
int count_bridges(const CSR<WeightType>& graph);

#endif  // MODULES_ALGORITHMS_INCLUDE_FIND_BRIDGES_H_
