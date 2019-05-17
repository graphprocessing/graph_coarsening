// Copyright [year] <Copyright Owner>
#ifndef MODULES_DATA_STRUCTURES_INCLUDE_ADJACENCY_LIST_H_
#define MODULES_DATA_STRUCTURES_INCLUDE_ADJACENCY_LIST_H_
#include "../../pch/include/precomp.h"

template <typename WeightType>
struct AL : public Graph<WeightType> {
 public:
    std::vector <std::vector <int>> edges;
    std::vector <std::vector <WeightType>> weights;
    std::vector <int> weight_vertex;
    AL<WeightType>(const CSR<WeightType>& csr, ...);
    AL<WeightType>() = default;
    bool get_neighbours(std::vector <std::pair<int, WeightType>>* neighbours,
        int vertex, int anc) const override;
    bool read(const std::string& path) override;
    bool write(const std::string& path) override;
    template <typename T>
    friend std::ostream& operator<<(std::ostream& out, const AL<T>& graph);
};

template <typename WeightType>
AL<WeightType>::AL(const CSR<WeightType>& csr, ...) {
    this->n = csr.n;
    edges.resize(this->n);
    weights.resize(this->n);
    for (unsigned i = 0; i < csr.offset.size() - 1; i++) {
        for (int j = csr.offset[i]; j < csr.offset[i + 1]; j++) {
            edges[i].push_back(csr.edges[j]);
            weights[i].push_back(csr.weights[j]);
        }
    }
    this->weight_vertex.resize(csr.n);
    for (int i = 0; i < csr.n; i++) {
        this->weight_vertex[i] = csr.weight_vertex[i];
    }
}

template <typename WeightType>
bool AL<WeightType>::get_neighbours(
        std::vector <std::pair<int, WeightType>>* neighbours,
        int vertex, int anc) const {
    for (unsigned i = 0; i < edges[vertex].size(); i++) {
        std::pair<int, WeightType> to = {edges[vertex][i], weights[vertex][i]};
        neighbours->push_back(to);
    }
    return true;
}

template <typename WeightType>
bool AL<WeightType>::read(const std::string &file) {
    std::ifstream file_to_open(file.c_str(), std::ios::binary);
    if (file_to_open.is_open()) {
        file_to_open.read(reinterpret_cast<char *>(&this->n), sizeof(int));
        edges.resize(this->n);
        weight_vertex.resize(this->n);
        int k;
        file_to_open.read(reinterpret_cast<char *>(&k), sizeof(int));
        int value;
        while (file_to_open.read(reinterpret_cast<char *>(&value),
                sizeof(value))) {
            if (value == -1) {
                file_to_open.read(reinterpret_cast<char *>(&value),
                    sizeof(value));
                k = value;
            } else {
                int to = value;
                WeightType len;
                file_to_open.read(reinterpret_cast<char *>(&len),
                    sizeof(WeightType));
                if (k < this->n) {
                    edges[k].push_back(to);
                    weights[k].push_back(len);
                }
            }
        }
    }
    return true;
}

template <typename WeightType>
bool AL<WeightType>::write(const std::string& path) {
    std::ofstream file_to_write(path, std::ios::binary);
    int size = edges.size();
    file_to_write.write(reinterpret_cast<char *>(&size), sizeof(int));
    for (unsigned i = 0; i < edges.size(); i++) {
        file_to_write.write(reinterpret_cast<char *>(&i), sizeof(int));
        for (unsigned j = 0; j < edges[i].size(); j++) {
            int to = edges[i][j];
            WeightType len = weights[i][j];
            file_to_write.write(reinterpret_cast<char *>(&to), sizeof(int));
            file_to_write.write(reinterpret_cast<char *>(&len),
                                                        sizeof(WeightType));
        }
        int val = -1;
        file_to_write.write(reinterpret_cast<char *>(&val), sizeof(int));
    }
    return true;
}

template <typename WeightType>
std::ostream& operator<<(std::ostream& out, const AL<WeightType>& graph) {
    for (int i = 0; i < graph.n; ++i) {
        std::cout << i << ": ";
        for (unsigned j = 0; j < graph.edges[i].size(); ++j) {
            std::cout << "[" << graph.edges[i][j] << ", "
                      << graph.weights[i][j] << "] ";
        }
        std::cout << std::endl;
    }
    return out;
}

#endif  // MODULES_DATA_STRUCTURES_INCLUDE_ADJACENCY_LIST_H_
