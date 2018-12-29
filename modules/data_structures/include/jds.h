// Copyright [year] <Copyright Owner>
#ifndef MODULES_DATA_STRUCTURES_INCLUDE_JDS_H_
#define MODULES_DATA_STRUCTURES_INCLUDE_JDS_H_
#include "../../pch/include/precomp.h"

template <typename WeightType>
struct JDS : public Graph<WeightType> {
 public:
    std::vector <WeightType> val;
    std::vector <int> col_ind;
    std::vector <int> offset;
    std::vector <int> parm;
    JDS(const CSR<WeightType>& csr, ...);
    JDS() = default;
    bool get_neighbours(std::vector <std::pair<int, WeightType>>* neighbours,
        int vertex, int anc) const override;
    bool read(const std::string& path) override;
    bool write(const std::string& path) override;
};

#endif  // MODULES_DATA_STRUCTURES_INCLUDE_JDS_H_
