// Copyright [year] <Copyright Owner>
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include "../data_structures/include/graph.h"
#include "../data_structures/include/csr.h"
#include "../generators/include/washington_test.h"
#include "../generators/include/zadeh_test.h"
#include "../generators/include/cube_test.h"
#include "../data_structures/include/adjacency_list.h"
#include "../data_structures/include/jds.h"
#include "../algorithms/include/random_matching.h"
#include "../algorithms/include/hard_matching.h"
#include "../common/include/timer.h"

int main(int argc, char** argv) {
    std::cout << "main" << std::endl;
    // Timer sample
    std::cout << std::fixed;
    std::cout << "Execution time for washington_test (n = 2): "
                << Timer::calculate(washington_test, 2, false)
                << " s" << std::endl << std::endl;
    std::cout << "Execution time for washington_test (n = 1e6): "
                << Timer::calculate(washington_test,
                    1000000, false)
                << " s" << std::endl << std::endl;
    return 0;
}
