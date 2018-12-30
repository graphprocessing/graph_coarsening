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
 private:
    bool compare(std::pair<int, int> a, std::pair<int, int> b);
};

template <typename WeightType>
bool JDS<WeightType>::compare(std::pair<int, int> a, std::pair<int, int> b) {
    return a.first > b.first;
}

template <typename WeightType>
JDS<WeightType>::JDS(const CSR<WeightType>& csr, ...) {
    this->n = csr.n;
    std::vector<std::pair<int, int>> priority;
    for (unsigned i = 1; i < csr.offset.size(); i++) {
        priority.push_back(std::make_pair(csr.offset[i] -
        csr.offset[i - 1], i - 1));
    }
    sort(priority.begin(), priority.end(), this->compare);
    offset.push_back(0);
    for (unsigned i = 0; i < priority.size(); i++) {
        parm.push_back(priority[i].second);
    }
    int temp1 = 0;
    unsigned j_size = parm.size();
    unsigned t_sz = 0;
    for (int i = static_cast<int>(priority.size() - 1); i >= 0; i--) {
        int temp = priority[i].first - temp1;
        for (int j = 0; j < temp; j++) {
            t_sz += j_size;
            offset.push_back(static_cast<int>(t_sz));
        }
        j_size--;
        temp1 += temp;
    }
    for (unsigned i = 0; i < offset.size() - 1; i++) {
        for (int j = offset[i], k = 0; j < offset[i + 1]; j++, k++) {
            val.push_back(csr.edges[csr.offset[parm[k]] + i].second);
            col_ind.push_back(csr.edges[csr.offset[parm[k]] + i].first);
        }
    }
}

template <typename WeightType>
bool JDS<WeightType>::get_neighbours(
        std::vector <std::pair<int, WeightType>>* neighbours,
        int vertex, int anc) const {
    int j = 0;
    while (parm[j] != vertex) {
        j++;
    }
    int i = 0;
    while ((i < static_cast<int>(offset.size() - 1)) &&
    (offset[i] + j < offset[i + 1])) {
        std::pair<int, int> to =
        std::make_pair(col_ind[offset[i] + j], val[offset[i] + j]);
        neighbours->push_back(to);
        i++;
    }
    return true;
}

template <typename WeightType>
bool JDS<WeightType>::read(const std::string &file) {
    std::ifstream file_to_open(file.c_str(), std::ios::binary);
    if (!file_to_open.is_open()) {
        return false;
    } else {
        file_to_open.read(reinterpret_cast<char*>(&this->n), sizeof(int));
        int size = 0;
        file_to_open.read(reinterpret_cast<char *>(&size), sizeof(int));
        val.resize(size);
        col_ind.resize(size);
        for (int i = 0; i < size; i++) {
            file_to_open.read(reinterpret_cast<char *>(&val[i]),
                                                sizeof(WeightType));
            file_to_open.read(reinterpret_cast<char *>(&col_ind[i]),
            sizeof(int));
        }
        file_to_open.read(reinterpret_cast<char *>(&size), sizeof(int));
        offset.resize(size);
        for (int i = 0; i < size; i++) {
            file_to_open.read(reinterpret_cast<char *>(&offset[i]),
            sizeof(int));
        }
        file_to_open.read(reinterpret_cast<char *>(&size), sizeof(int));
        parm.resize(size);
        for (int i = 0; i < size; i++) {
            file_to_open.read(reinterpret_cast<char *>(&parm[i]), sizeof(int));
        }
        return true;
    }
}

template <typename WeightType>
bool JDS<WeightType>::write(const std::string& path) {
    std::ofstream file_to_write(path, std::ios::binary);
    if (!file_to_write.is_open())
        return false;
    file_to_write.write(reinterpret_cast<char*>(&this->n), sizeof(int));
    int size = val.size();
    file_to_write.write(reinterpret_cast<char *>(&size), sizeof(int));
    for (unsigned i = 0; i < val.size(); i++) {
        WeightType value = val[i], col = col_ind[i];
        file_to_write.write(reinterpret_cast<char *>(&value),
                                                    sizeof(WeightType));
        file_to_write.write(reinterpret_cast<char *>(&col), sizeof(int));
    }
    size = offset.size();
    file_to_write.write(reinterpret_cast<char *>(&size), sizeof(int));
    for (unsigned i = 0; i < offset.size(); i++) {
        int to = offset[i];
        file_to_write.write(reinterpret_cast<char *>(&to), sizeof(int));
    }
    size = parm.size();
    file_to_write.write(reinterpret_cast<char *>(&size), sizeof(int));
    for (unsigned i = 0; i < parm.size(); i++) {
        int to = parm[i];
        file_to_write.write(reinterpret_cast<char *>(&to), sizeof(int));
    }
    file_to_write.close();
    return true;
}


#endif  // MODULES_DATA_STRUCTURES_INCLUDE_JDS_H_
