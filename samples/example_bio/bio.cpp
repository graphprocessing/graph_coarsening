// Copyright [year] <Copyright Owner>
#include "modules/pch/include/precomp.h"
#include "modules/pipelines/prepare.h"
#include "modules/pipelines/launch.h"

int main(int argc, char** argv) {
    std::cout << "+" << std::endl;
    CSR <int> g;
    g.read("../graph_data/bio.bin");
    g.write("../graph_data/1.bin");
    std::cout << "g1 complete" << std::endl;
    std::cout << "n: " << g.n << std::endl;
    // CSR <int> g2 = g;
    // for (int i = 0; i < 10; ++i) {
    //     g2 = graph_coarsening(g2, random_matching(g2));
    //     std::cout << "g2 " << i << " n: " << g2.n <<
    //                  " m: " << g2.edges.size() << std::endl;
    // }
    // g2.write("../graph_data/2.bin");
    CSR <int> g3 = g;
    for (int i = 0; i < 10; ++i) {
        g3 = graph_coarsening(g3, hard_matching(g3));
        std::cout << "g3 " << i << " n: " << g3.n <<
                     " m: " << g3.edges.size() << std::endl;
    }
    g3.write("../graph_data/3.bin");
    return 0;
}
