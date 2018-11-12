// Copyright [year] <Copyright Owner>
#include <iostream>
#include <vector>
#include "../data_structures/include/graph.h"
#include "../data_structures/include/csr.h"
#include "../generators/include/generator.h"

int main(int argc, char** argv) {
    std::cout << "This start application!" << '\n';

    // CSR sample
    CSR csr = washington_test(2);
    for (unsigned i = 0; i < csr.offset.size(); ++i)
        std::cout << csr.offset[i] << " ";
    std::cout << std::endl;
    for (unsigned i = 0; i < csr.edges.size(); ++i)
        std::cout << csr.edges[i].first << " ";
    std::cout << std::endl;
    std::cout << "BFS 0-2: " << csr.bfs(0, 2) << std::endl;
    std::cout << "BFS 0-8: " << csr.bfs(0, 8) << std::endl;
    std::cout << "BFS 0-2: " << csr.Dijkstra(0, 2) << std::endl;
    std::cout << "BFS 0-8: " << csr.Dijkstra(0, 8) << std::endl;
    std::vector <int> dfs_res = csr.dfs(0);
    for (int i = 0; i < csr.n; ++i)
        std::cout << "vertex " << i << ", depth " << dfs_res[i] << std::endl;
    std::cout << std::endl;
    // End of CSR

    return 0;
}
