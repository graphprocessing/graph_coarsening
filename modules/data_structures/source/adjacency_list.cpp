// Copyright [year] <Copyright Owner>
#include "../../pch/include/precomp.h"

template <typename WeightType>
AL<WeightType>::AL(const CSR<WeightType>& csr, ...) {
    this->n = csr.n;
    edges.resize(this->n);
    for (unsigned i = 0; i < csr.offset.size() - 1; i++) {
        for (int j = csr.offset[i]; j < csr.offset[i + 1]; j++) {
            edges[i].push_back(
                std::make_pair(csr.edges[j].first, csr.edges[j].second));
        }
    }
}

template <typename WeightType>
bool AL<WeightType>::get_neighbours(std::vector <std::pair<int, WeightType>>* neighbours,
        int vertex, int anc) const {
    for (unsigned i = 0; i < edges[vertex].size(); i++) {
        std::pair<int, int> to = edges[vertex][i];
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
                    edges[k].push_back(std::make_pair(to, len));
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
            file_to_write.write(reinterpret_cast<char *>(&len), sizeof(WeightType));
        }
        int val = -1;
        file_to_write.write(reinterpret_cast<char *>(&val), sizeof(int));
    }
    return true;
}
