// Copyright [year] <Copyright Owner>
#ifndef MODULES_DATA_STRUCTURES_INCLUDE_GRAPH_H_
#define MODULES_DATA_STRUCTURES_INCLUDE_GRAPH_H_
#include "../../pch/include/precomp.h"

template <typename WeightType>
struct JDS;

template <typename WeightType>
struct CSR;

template <typename WeightType>
struct AL;

template <typename WeightType>
struct Graph {
 public:
    int n = 0;
    int bfs(int from, int to);
    std::vector <int> dfs(int root);
    int Dijkstra(int from, int to);
    virtual bool get_neighbours(std::vector <std::pair<int, WeightType>>* neighbours,
        int vertex, int anc) const = 0;
    virtual bool read(const std::string& path) = 0;
    virtual bool write(const std::string& path) = 0;
 private:
    void dfs_recursion(std::vector <int>* pd,
        std::vector <char>* pwas, int x, int anc);
};

#endif  // MODULES_DATA_STRUCTURES_INCLUDE_GRAPH_H_
