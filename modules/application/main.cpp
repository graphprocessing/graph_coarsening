// Copyright [year] <Copyright Owner>
#include <iostream>
#include <vector>
#include "../data_structures/include/graph.h"
#include "../data_structures/include/csr.h"
#include "../generators/include/generator.h"
#include "../data_structures/include/adjacency_list.h"
#include "../algorithms/include/random_matching.h"

int main(int argc, char** argv) {
    // CSR sample
    CSR csr_graph = washington_test(2);
    if (csr_graph.write("csr.bin")) {
        std::cout << "Graph is written to the file successfully" << std::endl;
    } else {
        std::cout << "Error with writing graph to file" << std::endl;
        return 1;
    }
    CSR csr;
    if (csr.read("csr.bin")) {
        std::cout << "Graph is read from the file successfully" << std::endl;
    } else {
        std::cout << "Error with reading graph from file" << std::endl;
        return 1;
    }
    for (unsigned i = 0; i < csr.offset.size(); ++i)
        std::cout << csr.offset[i] << " ";
    std::cout << std::endl;
    for (unsigned i = 0; i < csr.edges.size(); ++i)
        std::cout << csr.edges[i].first << " ";
    std::cout << std::endl;
    std::cout << "BFS 0-2: " << csr.bfs(0, 2) << std::endl;
    std::cout << "BFS 0-8: " << csr.bfs(0, 8) << std::endl;
    std::cout << "Dijkstra 0-2: " << csr.Dijkstra(0, 2) << std::endl;
    std::cout << "Dijkstra 0-8: " << csr.Dijkstra(0, 8) << std::endl;
    std::vector <int> dfs_res = csr.dfs(0);
    for (int i = 0; i < csr.n; ++i)
        std::cout << "vertex " << i << ", depth " << dfs_res[i] << std::endl;
    std::cout << std::endl;
    // End of CSR

    // AL sample
    AL al(csr_graph);
    al.write("al.bin");
    AL al1;
    al1.read("al.bin");
    for (unsigned i = 0; i < al1.edges.size(); i++) {
        std::cout << i << ": ";
        for (unsigned j = 0; j < al1.edges[i].size(); j++) {
            std::cout << al1.edges[i][j].first << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "BFS 0-2: " << al1.bfs(0, 2) << std::endl;
    std::cout << "BFS 0-8: " << al1.bfs(0, 8) << std::endl;
    std::cout << "Dijkstra 0-2: " << al1.Dijkstra(0, 2) << std::endl;
    dfs_res = al1.dfs(0);
    for (int i = 0; i < al1.n; i++)
        std::cout << "vertex " << i << ", depth " << dfs_res[i] << std::endl;
    std::cout << std::endl;
    // End of AL

    std::cout << std::endl << std::endl << "Matching: " << std::endl;
    AL mtch = random_matching(al1);
    for (unsigned i = 0; i < mtch.edges.size(); i++) {
        std::cout << i << ": ";
        for (unsigned j = 0; j < mtch.edges[i].size(); j++) {
            std::cout << mtch.edges[i][j].first << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
