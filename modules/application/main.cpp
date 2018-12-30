// Copyright [year] <Copyright Owner>
#include "../pch/include/precomp.h"
#include "../pipelines/prepare.h"
#include "../pipelines/launch.h"

int main(int argc, char** argv) {
    std::cout << "pipelines" << std::endl;
    Pipeline::prepare();
    Pipeline::launch();
    std::cout << "main" << std::endl;
    // Timer sample
    std::cout << std::fixed;
    std::cout << "Execution time for washington_test (n = 2): "
                << Timer::calculate(washington_test<int>, 2, false)
                << " s" << std::endl << std::endl;
    std::cout << "Execution time for washington_test (n = 1e6): "
                << Timer::calculate(washington_test<int>,
                    1000000, false)
                << " s" << std::endl << std::endl;
    std::cout << "graph_visualization" << std::endl;
    std::ofstream out("graph.txt");
    AL <int> g1 = washington_test<int>(2);
    for (int i = 0; i < g1.n; ++i) {
        std::vector <std::pair <int, int>> neighbours;
        g1.get_neighbours(&neighbours, i, i);
        for (unsigned j = 0; j < neighbours.size(); ++j)
            out << i << " " << neighbours[j].first << " "
                    << neighbours[j].second << std::endl;
    }
    out.close();
    return 0;
}
