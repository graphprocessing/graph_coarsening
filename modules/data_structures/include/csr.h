// Copyright [year] <Copyright Owner>
#ifndef MODULES_DATA_STRUCTURES_INCLUDE_CSR_H_
#define MODULES_DATA_STRUCTURES_INCLUDE_CSR_H_
#include <vector>
#include <utility>
#include <string>
#include "./graph.h"

struct CSR : public Graph {
 public:
    std::vector <std::pair <int, int>> edges;
    std::vector <int> offset;
    CSR(const AL& al, ...);
    CSR(const JDS& jds, ...);
    bool get_neighbours(std::vector <std::pair <int, int>>* neighbours,
        int vertex, int anc) override;
    bool read(const std::string& path) override;
    bool write(const std::string& path) override;
};

#endif  // MODULES_DATA_STRUCTURES_INCLUDE_CSR_H_
