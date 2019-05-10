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
    bool get_neighbours(
        std::vector <std::pair <int, WeightType>>* neighbours,
        int vertex, int anc) const override;
    bool read(const std::string& path) override;
    bool write(const std::string& path) override;
};

template <typename WeightType>
CSR<WeightType>::CSR(const AL<WeightType>& al, ...) {
    this->n = al.n;
    offset.push_back(0);
    for (unsigned i = 0; i < al.edges.size(); ++i) {
        for (unsigned j = 0; j < al.edges[i].size(); ++j) {
            edges.emplace_back(al.edges[i][j]);
            weights.emplace_back(al.weights[i][j]);
        }
        offset.push_back(edges.size());
    }
    this->weight_vertex.resize(al.n);
    for (int i = 0; i < al.n; i++) {
        this->weight_vertex[i] = al.weight_vertex[i];
    }
}

template <typename WeightType>
CSR<WeightType>::CSR(const JDS<WeightType>& jds, ...) {
    this->n = jds.n;
    offset.push_back(0);
    std::vector <std::pair <int, int>> neighbours;
    for (int i = 0; i < this->n; ++i) {
        neighbours.clear();
        jds.get_neighbours(&neighbours, i, i);
        for (auto& y : neighbours) {
            edges.push_back(y.first);
            weights.push_back(y.second);
        }
        offset.push_back(edges.size());
    }
}

template <typename WeightType>
bool CSR<WeightType>::get_neighbours(
    std::vector <std::pair <int, WeightType>>* neighbours,
    int vertex, int anc) const {
    for (int i = offset[vertex]; i < offset[vertex+1]; ++i)
        neighbours->push_back({edges[i], weights[i]});
    return true;
}

template <typename WeightType>
bool CSR<WeightType>::read(const std::string& path) {
    std::ifstream in(path, std::ios::binary);
    if (!in.is_open())
        return false;
    int m;
    in.read(reinterpret_cast<char*>(&this->n), sizeof(int));
    in.read(reinterpret_cast<char*>(&m), sizeof(int));
    offset.resize(this->n + 1);
    edges.resize(m);
    weights.resize(m);
    for (int i = 0; i < m; ++i)
        in.read(reinterpret_cast<char*>(&edges[i]), sizeof(int));
    for (int i = 0; i <= this->n; ++i)
        in.read(reinterpret_cast<char*>(&offset[i]), sizeof(int));
    for (int i = 0; i < m; ++i) {
        in.read(reinterpret_cast<char*>(&weights[i]), sizeof(WeightType));
    }
    return true;
}

template <typename WeightType>
bool CSR<WeightType>::write(const std::string& path) {
    std::ofstream out(path, std::ios::binary);
    if (!out.is_open())
        return false;
    out.write(reinterpret_cast<char*>(&this->n), sizeof(int));
    int m = edges.size();
    out.write(reinterpret_cast<char*>(&m), sizeof(int));
    for (unsigned i = 0; i < edges.size(); ++i)
        out.write(reinterpret_cast<char*>(&edges[i]), sizeof(int));
    for (int i = 0; i <= this->n; ++i)
        out.write(reinterpret_cast<char*>(&offset[i]), sizeof(int));
    for (unsigned i = 0; i < edges.size(); ++i)
        out.write(reinterpret_cast<char*>(&weights[i]), sizeof(WeightType));
    out.close();
    return true;
}

#endif  // MODULES_DATA_STRUCTURES_INCLUDE_CSR_H_
