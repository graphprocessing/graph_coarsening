// Copyright [year] <Copyright Owner>
#ifndef MODULES_DATA_STRUCTURES_INCLUDE_JDS_H_
#define MODULES_DATA_STRUCTURES_INCLUDE_JDS_H_
#include <vector>
#include <utility>
#include <string>
#include "./graph.h"

struct JDS : public Graph {
 public:
    std::vector <int> val;
    std::vector <int> col_ind;
    std::vector <int> offset;
    JDS(const CSR& csr, ...);
    bool get_neighbours(std::vector <std::pair<int, int>>* neighbours,
        int vertex, int anc) override;
    bool read(const std::string& path) override;
    bool write(const std::string& path) override;
};

#endif  // MODULES_DATA_STRUCTURES_INCLUDE_JDS_H_
