// Copyright [year] <Copyright Owner>
#include "modules/pch/include/precomp.h"

int main(int argc, char** argv) {
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
    AL <int> gr = washington_test<int>(100);
    export_for_visualization(gr, "graph.txt");
    return 0;
}
