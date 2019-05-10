// Copyright [year] <Copyright Owner>
#include "../../modules/pch/include/precomp.h"
#include "gtest/gtest.h"

TEST(test, test1) {
    CSR<int> graph1 = washington_test<int>(2);
    for (int i = 0; i < graph1.n; i++) {
        std::cout << i << "- ";
        for (int j = graph1.offset[i]; j < graph1.offset[i + 1]; j++) {
            int to = graph1.edges[j];
            std::cout << to << " ";
        }
        std::cout << std::endl;
    }
    CSR<int> graph = graph_coarsening(graph1,
        [](const CSR<int>& graph) -> Matching {
        return hard_matching<int>(graph);
    });
    for (int i = 0; i < graph.n; i++) {
        std::cout << i << "- ";
        for (int j = graph.offset[i]; j < graph.offset[i + 1]; j++) {
            int to = graph.edges[j];
            int weight = graph.weights[j];
            std::cout << to << "-" << weight << " ";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < graph.n; i++) {
        std::cout << graph.weight_vertex[i] << " ";
    }
    std::cout << std::endl;
}
