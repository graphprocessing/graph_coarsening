// Copyright [year] <Copyright Owner>
#include "../../pch/include/precomp.h"

void PipelineParser::Pipeline::perform_commands() {
    auto get_param = [](std::map <std::string, std::string>& command,
                                std::string param) -> std::string {
        if (command.find(param) != command.end())
            return command[param];
        throw std::runtime_error("Parameter " + param + " is not found");
    };
    auto get_param_no_throw = [](std::map <std::string, std::string>& command,
                                std::string param) -> std::string {
        if (command.find(param) != command.end())
            return command[param];
        return "_no_parameter";
    };
    for (auto& command : commands) {
        if (command.find("input") != command.end()) {
            std::cout << "Started input command" << std::endl;
            graph.read(get_param(command, "input"));
            std::cout << "Finished input command" << std::endl;
        } else if (command.find("graph_generate") != command.end()) {
            std::cout << "Started graph_generate command" << std::endl;
            std::string graph_type = get_param(command, "graph_generate");
            int n = std::stoi(get_param(command, "n"));
            int weighted = std::stoi(get_param(command, "weighted"));
            if (graph_type == "washington_test") {
                graph = washington_test<double>(n, weighted);
            } else if (graph_type == "zadeh_test") {
                graph = zadeh_test<double>(n, weighted);
            } else if (graph_type == "cube_test") {
                graph = cube_test<double>(n, weighted);
            } else if (graph_type == "cycle_generator") {
                graph = cycle_generator<double>(n, weighted);
            } else if (graph_type == "stars_generator") {
                graph = stars_generator<double>(n, weighted);
            } else if (graph_type == "chain_generator") {
                int m = std::stoi(get_param(command, "m"));
                graph = chain_generator<double>(n, m, weighted);
            } else {
                throw std::runtime_error("Unknown generator type: "
                                        + graph_type);
            }
            std::cout << "Finished graph_generate command" << std::endl;
        } else if (command.find("coarsening") != command.end()) {
            std::cout << "Started coarsening command" << std::endl;
            std::string coarsening_type = get_param(command, "coarsening");
            std::string type = get_param(command, "type");
            std::string until_str = get_param_no_throw(command, "until");
            std::string trigger_str = get_param_no_throw(command, "trigger");
            std::string count_str = get_param_no_throw(command, "count");
            std::string subtype = get_param_no_throw(command, "subtype");
            int lower_bound =
                get_param_no_throw(command, "lower_bound") == "_no_parameter" ?
                    0 :
                    std::stoi(get_param_no_throw(command, "lower_bound"));
            int upper_bound =
                get_param_no_throw(command, "upper_bound") == "_no_parameter" ?
                    INT_MAX :
                    std::stoi(get_param_no_throw(command, "upper_bound"));
            int count = 1;
            if (count_str != "_no_parameter")
                count = std::stoi(count_str);
            if (until_str != "count" &&
                until_str != "trigger" &&
                until_str != "_no_parameter")
                throw std::runtime_error("Unknown 'until' parameter");
            auto check = [&]() -> bool {
                if (until_str == "count" || until_str == "_no_parameter") {
                    return count > 0;
                } else if (until_str == "trigger") {
                    int cur = std::stoi(evaluate_characteristic(trigger_str));
                    return !(cur >= lower_bound && cur <= upper_bound);
                } else {
                    throw std::runtime_error("Unknown 'until' parameter");
                }
            };
            if (coarsening_type == "matching") {
                if (type == "random") {
                    for (int i = 0; check(); --count, ++i) {
                        graph = graph_coarsening(graph,
                                    [](const CSR<double>& graph) -> Matching {
                            return random_matching<double>(graph);
                        });
                        std::cout << "iteration: " << i << " n: " << graph.n
                                << " m: " << graph.edges.size() << std::endl;
                    }
                } else if (type == "hard") {
                    for (int i = 0; check(); --count, ++i) {
                        graph = graph_coarsening(graph,
                                [](const CSR<double>& graph) -> Matching {
                            return hard_matching<double>(graph);
                            });
                        std::cout << "iteration: " << i << " n: " << graph.n
                                << " m: " << graph.edges.size() << std::endl;
                    }
                } else if (type == "edmonds") {
                    for (int i = 0; check(); --count, ++i) {
                        graph = graph_coarsening(graph,
                                    [](const CSR<double>& graph) -> Matching {
                            return edmonds<double>(graph);
                            });
                        std::cout << "iteration: " << i << " n: " << graph.n
                                << " m: " << graph.edges.size() << std::endl;
                    }
                } else if (type == "gpa") {
                    if (subtype == "random") {
                        for (int i = 0; check(); --count, ++i) {
                            graph = graph_coarsening(graph,
                                [](const CSR<double>& graph) -> Matching {
                                    return GPA(graph,
                                    [](const CSR<double>& graph) -> Matching {
                                        return random_matching(graph);
                                    });});
                            std::cout << "iteration: " << i << " n: "
                                << graph.n << " m: " << graph.edges.size()
                                << std::endl;
                        }
                    } else if (subtype == "hard") {
                        for (int i = 0; check(); --count, ++i) {
                            graph = graph_coarsening(graph,
                                [](const CSR<double>& graph) -> Matching {
                                    return GPA(graph,
                                    [](const CSR<double>& graph) -> Matching {
                                        return hard_matching(graph);
                                    });});
                            std::cout << "iteration: " << i << " n: "
                                << graph.n << " m: " << graph.edges.size()
                                << std::endl;
                        }
                    } else if (subtype == "edmonds") {
                        for (int i = 0; check(); --count, ++i) {
                            graph = graph_coarsening(graph,
                                [](const CSR<double>& graph) -> Matching {
                                    return GPA(graph,
                                    [](const CSR<double>& graph) -> Matching {
                                        return edmonds(graph);
                                    });});
                            std::cout << "iteration: " << i << " n: "
                                << graph.n << " m: " << graph.edges.size()
                                << std::endl;
                        }
                    } else if (subtype == "mwm") {
                        for (int i = 0; check(); --count, ++i) {
                            graph = graph_coarsening(graph,
                                [](const CSR<double>& graph) -> Matching {
                                    return GPA(graph,
                                    [](const AL<double>& graph) -> Matching {
                                        return max_weight_matching(graph);
                                    });});
                            std::cout << "iteration: " << i << " n: "
                                << graph.n << " m: " << graph.edges.size()
                                << std::endl;
                        }
                    } else if (subtype == "_no_parameter") {
                        throw std::runtime_error("Missing subtype for " + type);
                    } else {
                        throw std::runtime_error("Unknown subtype: " + type);
                    }
                } else if (type == "pga") {
                    if (subtype == "random") {
                        for (int i = 0; check(); --count, ++i) {
                            graph = graph_coarsening(graph,
                                [](const CSR<double>& graph) -> Matching {
                                    return PGA(graph,
                                    [](const CSR<double>& graph) -> Matching {
                                        return random_matching(graph);
                                    });});
                            std::cout << "iteration: " << i << " n: "
                                << graph.n << " m: " << graph.edges.size()
                                << std::endl;
                        }
                    } else if (subtype == "hard") {
                        for (int i = 0; check(); --count, ++i) {
                            graph = graph_coarsening(graph,
                                [](const CSR<double>& graph) -> Matching {
                                    return PGA(graph,
                                    [](const CSR<double>& graph) -> Matching {
                                        return hard_matching(graph);
                                    });});
                            std::cout << "iteration: " << i << " n: "
                                << graph.n << " m: " << graph.edges.size()
                                << std::endl;
                        }
                    } else if (subtype == "edmonds") {
                        for (int i = 0; check(); --count, ++i) {
                            graph = graph_coarsening(graph,
                                [](const CSR<double>& graph) -> Matching {
                                    return PGA(graph,
                                    [](const CSR<double>& graph) -> Matching {
                                        return edmonds(graph);
                                    });});
                            std::cout << "iteration: " << i << " n: "
                                << graph.n << " m: " << graph.edges.size()
                                << std::endl;
                        }
                    } else if (subtype == "mwm") {
                        for (int i = 0; check(); --count, ++i) {
                            graph = graph_coarsening(graph,
                                [](const CSR<double>& graph) -> Matching {
                                    return PGA(graph,
                                    [](const AL<double>& graph) -> Matching {
                                        return max_weight_matching(graph);
                                    });});
                            std::cout << "iteration: " << i << " n: "
                                << graph.n << " m: " << graph.edges.size()
                                << std::endl;
                        }
                    } else if (subtype == "_no_parameter") {
                        throw std::runtime_error("Missing subtype for " + type);
                    } else {
                        throw std::runtime_error("Unknown subtype: " + type);
                    }
                } else if (type == "lam") {
                    for (int i = 0; check(); --count, ++i) {
                        graph = graph_coarsening(graph,
                                    [](const CSR<double>& graph) -> Matching {
                            return LAM<double>(graph);
                            });
                        std::cout << "iteration: " << i << " n: " << graph.n
                                << " m: " << graph.edges.size() << std::endl;
                    }
                } else {
                    throw std::runtime_error("Unknown matching: " + type);
                }
            } else {
                throw std::runtime_error("Unknown coarsening: "
                                        + coarsening_type);
            }
            std::cout << "Finished coarsening command" << std::endl;
        } else if (command.find("graph_output") != command.end()) {
            std::cout << "Started graph_output command" << std::endl;
            graph.read(get_param(command, "graph_output"));
            std::cout << "Finished graph_output command" << std::endl;
        } else if (command.find("graph_export_edges") != command.end()) {
            std::cout << "Started graph_export_edges command" << std::endl;
            export_for_visualization(graph,
                                get_param(command, "graph_export_edges"));
            std::cout << "Finished graph_export_edges command" << std::endl;
        } else if (command.find("evaluate") != command.end()) {
            std::cout << "Started evaluate command" << std::endl;
            std::string characteristic = get_param(command, "evaluate");
            evaluate_characteristic(characteristic);
            std::cout << "Finished evaluate command" << std::endl;
        } else if (command.find("table_output") != command.end()) {
            std::cout << "Started table_output command" << std::endl;
            std::string file_name = get_param(command, "table_output");
            int append = std::stoi(get_param(command, "append"));
            std::ofstream f;
            if (append)
                f.open(file_name, std::ios::app);
            else
                f.open(file_name);
            for (int i = 0; i < charactreistics_count; ++i)
                f << table[i] << " ";
            f << std::endl;
            f.close();
            std::cout << "Finished table_output command" << std::endl;
        } else if (command.find("convert") != command.end()) {
            std::cout << "Started convert command" << std::endl;
            std::string convert_type = get_param(command, "convert");
            if (convert_type == "undirected") {
                graph = convert_to_undirected_graph<double>(graph);
            } else if (convert_type == "unweighted") {
                for (unsigned i = 0; i < graph.weights.size(); ++i)
                    graph.weights[i] = 1;
            } else {
                throw std::runtime_error("Unknown conversion"
                                         " type: " + convert_type);
            }
            std::cout << "Finished convert command" << std::endl;
        } else if (command.find("do") != command.end()) {
            std::cout << "Started do command" << std::endl;
            std::string pipeline_name = get_param(command, "do");
            bool done = false;
            for (unsigned i = 0; i < pipelines->size(); ++i) {
                if ((*pipelines)[i].name == pipeline_name) {
                    std::cout << "Starting execution of pipeline \""
                            << pipeline_name << "\" via do command"
                            << std::endl;
                    (*pipelines)[i].perform_commands();
                    std::cout << "Finished execution of pipeline \""
                            << pipeline_name << "\" via do command"
                            << std::endl;
                    done = true;
                    break;
                }
            }
            if (!done)
                throw std::runtime_error("Unable to find pipeline " +
                                        pipeline_name);
            std::cout << "Finished do command" << std::endl;
        } else {
            std::stringstream s;
            s << std::endl;
            for (auto& a : command)
                s << " - " << a.first << ": " << a.second << std::endl;
            throw std::runtime_error("Unknown command" + s.str());
        }
    }
}
