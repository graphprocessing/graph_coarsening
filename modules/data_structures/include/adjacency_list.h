// Copyright [year] <Copyright Owner>
#ifndef MODULES_DATA_STRUCTURES_INCLUDE_ADJACENCY_LIST_H_
#define MODULES_DATA_STRUCTURES_INCLUDE_ADJACENCY_LIST_H_
#include "../../pch/include/precomp.h"

template <typename WeightType>
struct AL : public Graph<WeightType> {
 public:
    std::vector <std::vector <int>> edges;
    std::vector <std::vector <WeightType>> weights;
    AL<WeightType>(const CSR<WeightType>& csr, ...);
    AL<WeightType>() = default;
    bool get_neighbours(std::vector <std::pair<int, WeightType>>* neighbours,
        int vertex, int anc) const override;
    bool read(const std::string& path) override;
    bool write(const std::string& path) override;
};

#endif  // MODULES_DATA_STRUCTURES_INCLUDE_ADJACENCY_LIST_H_
