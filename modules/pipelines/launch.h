// Copyright [year] <Copyright Owner>
#ifndef MODULES_PIPELINES_LAUNCH_H_
#define MODULES_PIPELINES_LAUNCH_H_
#include "../pch/include/precomp.h"
#include "./prepare.h"

namespace Pipeline {
    std::vector <std::function <std::string(const std::string&)>> pipelines;
    const std::string launch() {
        const std::string output_file_name =
                std::string("../graph_data/pipeline_") +
                std::string(COMPILER_NAME) + std::string(".txt");
        std::ofstream out(output_file_name);
        int index = 0;
        for (auto pipeline : pipelines) {
            CSR graph;
            std::string new_file;
            auto fu = [&]() {
                new_file = pipeline(graph_files[index++]);
            };
            double pipeline_time = Timer::calculate(fu);
            graph.read(new_file);
            #if 0
                AL g(graph);
                for (int i = 0; i < g.n; ++i) {
                    std::cout << i << " : ";
                    for (unsigned j = 0; j < g.edges[i].size(); ++j)
                        std::cout << g.edges[i][j].first << " ";
                    std::cout << std::endl;
                }
            #endif  // 0
            // Characteristics export
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
                int max_weight = 0;
                for (int i = 0; i < graph.n; ++i) {
                    int current_weight = 0;
                    for (int j = graph.offset[i]; j < graph.offset[i+1]; ++j)
                        current_weight += graph.edges[j].second;
                    max_weight = std::max(max_weight, current_weight);
                }
                out << max_weight << " ";
            }
            // 6. Graph diameter
            out << graph_diameter(graph) << " ";
            // 7. Graph radius
            out << graph_radius(graph) << " ";
            // 8. Average number of vertexes in strongly connected component
            {
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
            // 9. Number of bridges
            out << count_bridges(graph) << " ";
            // 10. Number of joint points
            out << count_joint_points(graph) << " ";
            // 11. Average eccentricity of vertexes
            {
                auto ecc = vertexes_eccentricity(graph);
                int ecc_sum = std::accumulate(begin(ecc), end(ecc), 0);
                out << static_cast<double>(ecc_sum) / graph.n << " ";
            }
            // 12. Sum of edges weight in minimal spanning tree
            out << get_cost_of_minimal_spanning_tree(graph) << " ";
        }
        return output_file_name;
    }
}  // namespace Pipeline

#endif  // MODULES_PIPELINES_LAUNCH_H_
