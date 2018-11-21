// Copyright [year] <Copyright Owner>
#include <iostream>
#include <vector>
#include <utility>
#include "../data_structures/include/graph.h"
#include "../data_structures/include/csr.h"
#include "../generators/include/washington_test.h"
#include "../generators/include/zadeh_test.h"
#include "../data_structures/include/adjacency_list.h"
#include "../data_structures/include/jds.h"
#include "../algorithms/include/random_matching.h"
#include "../algorithms/include/hard_matching.h"

int main(int argc, char** argv) {
    std::cout << "main" << std::endl;
    CSR g1 = washington_test(2);
    auto match = random_matching(g1);
    std::cout << "Done" << std::endl;
    // CSR g2 = zadeh_test(20, true);
    return 0;
}
