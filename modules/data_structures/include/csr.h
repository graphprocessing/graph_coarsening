// Copyright [year] <Copyright Owner>
#ifndef MODULES_DATA_STRUCTURES_INCLUDE_CSR_H_
#define MODULES_DATA_STRUCTURES_INCLUDE_CSR_H_
#include "../../pch/include/precomp.h"

template <typename WeightType>
struct CSR : public Graph<WeightType> {
 public:
    std::vector <int> edges;
    std::vector <WeightType> weights;
    std::vector <int> offset;
    CSR() = default;
    CSR(const AL<WeightType>& al, ...);
    CSR(const JDS<WeightType>& jds, ...);
    bool get_neighbours(std::vector <std::pair <int, WeightType>>* neighbours,
        int vertex, int anc) const override;
    bool read(const std::string& path) override;
    bool write(const std::string& path) override;
};

#endif  // MODULES_DATA_STRUCTURES_INCLUDE_CSR_H_
