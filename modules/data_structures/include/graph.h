// Copyright [year] <Copyright Owner>
#ifndef MODULES_DATA_STRUCTURES_INCLUDE_GRAPH_H_
#define MODULES_DATA_STRUCTURES_INCLUDE_GRAPH_H_
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <utility>

struct JDS;
struct CSR;
struct AL;

struct Graph {
 public:
    int n = 0;
    int bfs(int from, int to);
    std::vector <int> dfs(int root);
    int Dijkstra(int from, int to);
    virtual bool get_neighbours(std::vector <std::pair<int, int>>* neighbours,
        int vertex, int anc) = 0;
    virtual bool read(const std::string& path) = 0;
    virtual bool write(const std::string& path) = 0;
 private:
    void dfs_recursion(std::vector <int>* pd,
        std::vector <char>* pwas, int x, int anc);
};

#endif  // MODULES_DATA_STRUCTURES_INCLUDE_GRAPH_H_
