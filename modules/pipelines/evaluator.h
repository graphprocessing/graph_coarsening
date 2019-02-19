// Copyright [year] <Copyright Owner>
#ifndef MODULES_PIPELINES_EVALUATOR_H_
#define MODULES_PIPELINES_EVALUATOR_H_
#include "../pch/include/precomp.h"
#include "./pipeline_management.h"

namespace Pipeline {
    int eval1();
    int eval1_ = eval1();
    int eval1() {
        auto f = [&](const std::string& graph_before,
                     const std::string& graph_after,
                     const std::string& pipeline_name,
                     const double pipeline_time)
                -> std::string {
            const std::string output_file_name =
                "../graph_data/pipeline_results_" COMPILER_NAME ".txt";
            std::ofstream out;
            if (eval1_ == 0)
                out.open(output_file_name);
            else
                out.open(output_file_name, std::ios_base::app);
            ++eval1_;
            CSR<double> graph;
            graph.read(graph_after);
            // Evaluation
            out << graph_before << " ";
            out << pipeline_name << " ";
            // 1. Coarsening time
            out << pipeline_time << " ";
            // 2. Number of edges
            out << graph.edges.size() << " ";
            // 3. Number of vertexes
            out << graph.n << " ";
            // 4. Average degree of vertex
            out << static_cast<double>(graph.edges.size()) / graph.n << " ";
            // 5. Max vertex weight
            {
                double max_weight = 0;
                for (int i = 0; i < graph.n; ++i) {
                    double current_weight = 0;
                    for (int j = graph.offset[i];
                                j < graph.offset[i+1]; ++j)
                        current_weight += graph.weights[j];
                    max_weight = std::max(max_weight, current_weight);
                }
                out << max_weight << " ";
            }
            // 6. Graph diameter
            try {
                out << graph_diameter(graph) << " ";
            }
            catch (std::bad_alloc ba) {
                out << "std::bad_alloc" << " ";
                std::cerr << ba.what() << std::endl;
            }
            // 7. Graph radius
            try {
                out << graph_radius(graph) << " ";
            }
            catch (std::bad_alloc ba) {
                out << "std::bad_alloc" << " ";
                std::cerr << ba.what() << std::endl;
            }
            // 8. Average number of vertexes in strongly connected component
            try {
                std::vector <int> components;
                find_strongly_connected_components(&components, graph);
                std::map <int, int> m;
                for (int comp : components)
                    ++m[comp];
                int sum = 0;
                for (auto& comp : m)
                    sum += comp.second;
                out << static_cast<double>(sum) / m.size() << " ";
            }
            catch (std::bad_alloc ba) {
                out << "std::bad_alloc" << " ";
                std::cerr << ba.what() << std::endl;
            }
            // 9. Number of bridges
            try {
                out << count_bridges(graph) << " ";
            }
            catch (std::bad_alloc ba) {
                out << "std::bad_alloc" << " ";
                std::cerr << ba.what() << std::endl;
            }
            // 10. Number of joint points
            try {
                out << count_joint_points(graph) << " ";
            }
            catch (std::bad_alloc ba) {
                out << "std::bad_alloc" << " ";
                std::cerr << ba.what() << std::endl;
            }
            // 11. Average eccentricity of vertexes
            try {
                auto ecc = vertexes_eccentricity(graph);
                double ecc_sum = std::accumulate(begin(ecc), end(ecc), 0);
                out << static_cast<double>(ecc_sum) / graph.n << " ";
            }
            catch (std::bad_alloc ba) {
                out << "std::bad_alloc" << " ";
                std::cerr << ba.what() << std::endl;
            }
            // 12. Sum of edges weight in minimal spanning tree
            try {
                out << get_cost_of_minimal_spanning_tree(graph) << std::endl;
            }
            catch (std::bad_alloc ba) {
                out << "std::bad_alloc" << " ";
                std::cerr << ba.what() << std::endl;
            }
            // End of evaluation
            out.close();
            return output_file_name;
        };
        results_evaluators.push_back(f);
        return 0;
    }
}  // namespace Pipeline

#endif  // MODULES_PIPELINES_EVALUATOR_H_
