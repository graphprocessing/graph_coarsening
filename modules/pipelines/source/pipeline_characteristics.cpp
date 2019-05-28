// Copyright [year] <Copyright Owner>
#include "../../pch/include/precomp.h"

static const std::map<const std::string, const int> get_char_index = {
    {"pipeline_time", 1},
    {"vertexes", 2},
    {"edges", 3},
    {"avg_vertex_degree", 4},
    {"max_vertex_weight", 5},
    {"graph_diameter", 6},
    {"graph_radius", 7},
    {"vertexes_in_scc", 8},
    {"bridges", 9},
    {"joint_points", 10},
    {"avg_eccentricity", 11},
    {"cost_mst", 12}
};

void PipelineParser::Pipeline::set_characteristic
                            (const std::string &characteristic) {
    auto it = get_char_index.find(characteristic);
    if (it == get_char_index.end())
        throw std::runtime_error("Unknown characteristic"
                            "for evaluation: " + characteristic);
    table[it->second] = evaluate_characteristic(characteristic);
}

std::string PipelineParser::Pipeline::evaluate_characteristic
                            (const std::string &characteristic) {
    try {
        if (characteristic == "pipeline_time") {
            return std::to_string(omp_get_wtime() - start_time);
        } else if (characteristic == "vertexes") {
            return std::to_string(graph.n);
        } else if (characteristic == "edges") {
            return std::to_string(graph.edges.size());
        } else if (characteristic == "avg_vertex_degree") {
            double ans = static_cast<double>(graph.edges.size())
                                                        / graph.n;
            return std::to_string(ans);
        } else if (characteristic == "max_vertex_weight") {
            double max_weight = 0;
            for (int i = 0; i < graph.n; ++i) {
                double current_weight = 0;
                for (int j = graph.offset[i];
                            j < graph.offset[i+1]; ++j)
                    current_weight += graph.weights[j];
                max_weight = std::max(max_weight, current_weight);
            }
            return std::to_string(max_weight);
        } else if (characteristic == "graph_diameter") {
            return std::to_string(graph_diameter(graph));
        } else if (characteristic == "graph_radius") {
            return std::to_string(graph_radius(graph));
        } else if (characteristic == "vertexes_in_scc") {
            std::vector <int> components;
            find_strongly_connected_components(&components, graph);
            std::map <int, int> m;
            for (int comp : components)
                ++m[comp];
            int sum = 0;
            for (auto& comp : m)
                sum += comp.second;
            double ans = static_cast<double>(sum) / m.size();
            return std::to_string(ans);
        } else if (characteristic == "bridges") {
            return std::to_string(count_bridges(graph));
        } else if (characteristic == "joint_points") {
            return std::to_string(count_joint_points(graph));
        } else if (characteristic == "avg_eccentricity") {
            auto ecc = vertexes_eccentricity(graph);
            double ecc_sum = std::accumulate(begin(ecc), end(ecc), 0);
            double ans = static_cast<double>(ecc_sum) / graph.n;
            return std::to_string(ans);
        } else if (characteristic == "cost_mst") {
            return std::to_string(
                            get_cost_of_minimal_spanning_tree(graph));
        } else {
            throw std::runtime_error("Unknown characteristic"
                "for evaluation: " + characteristic);
        }
    } catch (std::bad_alloc& ba) {
        std::cerr << ba.what() << std::endl;
        std::cout << "Failed evaluate command" << std::endl;
    }
    return "";
}
