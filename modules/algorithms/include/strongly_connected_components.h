// Copyright [year] <Copyright Owner>
#ifndef MODULES_ALGORITHMS_INCLUDE_STRONGLY_CONNECTED_COMPONENTS_H_
#define MODULES_ALGORITHMS_INCLUDE_STRONGLY_CONNECTED_COMPONENTS_H_
#include "../../pch/include/precomp.h"

template <typename WeightType>
void find_strongly_connected_components(std::vector <int>* comp,
                        const CSR<WeightType>& graph);

#endif  // MODULES_ALGORITHMS_INCLUDE_STRONGLY_CONNECTED_COMPONENTS_H_
