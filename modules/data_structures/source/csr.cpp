// Copyright [year] <Copyright Owner>
#include <vector>
#include <utility>
#include <fstream>
#include "../include/graph.h"
#include "../include/csr.h"
#include "../include/adjacency_list.h"

CSR::CSR(const AL& al, ...) {
    offset.push_back(0);
    for (int i = 0; i < al.edges.size(); ++i) {
        for (int j = 0; j < al.edges[i].size(); ++j) {
            edges.emplace_back(al.edges[i][j]);
        }
        offset.push_back(edges.size());
    }
}

CSR::CSR(const JDS& jds, ...) {
    offset.push_back(0);
    // TO DO
}

bool CSR::get_neighbours(std::vector <std::pair <int, int>>* neighbours,
    int vertex, int anc) {
    std::vector <std::pair <int, int>>& vectorOfNeighbours = *neighbours;
    for (int i = offset[vertex]; i < offset[vertex+1]; ++i)
        vectorOfNeighbours.emplace_back(edges[i]);
    return true;
}

bool CSR::read(const std::string& path) {
    std::ifstream in(path, std::ios::binary);
    if (!in.is_open())
        return false;
    in.read(reinterpret_cast<char*>(&n), sizeof(int));
    int sz = 0;
    in.read(reinterpret_cast<char*>(&sz), sizeof(int));
    edges.resize(sz);
    for (int i = 0; i < sz; ++i) {
        in.read(reinterpret_cast<char*>(&edges[i].first), sizeof(int));
        in.read(reinterpret_cast<char*>(&edges[i].second), sizeof(int));
    }
    in.read(reinterpret_cast<char*>(&sz), sizeof(int));
    offset.resize(sz);
    for (int i = 0; i < sz; ++i)
        in.read(reinterpret_cast<char*>(&offset[i]), sizeof(int));
    return true;
}

bool CSR::write(const std::string& path) {
    std::ofstream out(path, std::ios::binary);
    if (!out.is_open())
        return false;
    out.write(reinterpret_cast<char*>(&n), sizeof(int));
    int sz = edges.size();
    out.write(reinterpret_cast<char*>(&sz), sizeof(int));
    for (auto y : edges) {
        out.write(reinterpret_cast<char*>(&y.first), sizeof(int));
        out.write(reinterpret_cast<char*>(&y.second), sizeof(int));
    }
    sz = offset.size();
    out.write(reinterpret_cast<char*>(&sz), sizeof(int));
    for (auto y : offset)
        out.write(reinterpret_cast<char*>(&y), sizeof(int));
    out.close();
    return true;
}
