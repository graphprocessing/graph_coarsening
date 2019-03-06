// Copyright [year] <Copyright Owner>
#include "modules/pch/include/precomp.h"

int main(int argc, char** argv) {
    for (int i = 1; i < argc; ++i) {
        CSR <double> graph;
        std::cout << "Reading " << argv[i] << std::endl;
        graph.read(argv[i]);
        graph = convert_to_undirected_graph<double>(graph);
        for (unsigned i = 0; i < graph.weights.size(); ++i)
            graph.weights[i] = 1;
        // std::cout << AL<double>(graph);
        graph.write("../graph_data/bio2.bin");
        std::cout << "Pipeline is done" << std::endl;
        CSR <double> result;
        result.read("../graph_data/pipeline_coarsening_random.bin");
        export_for_visualization(result, "../graph_data/bio_edges.txt");
    }
    return 0;
}
