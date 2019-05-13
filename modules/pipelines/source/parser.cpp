// Copyright [year] <Copyright Owner>
#include "../../pch/include/precomp.h"

PipelineParser::PipelineParser(const std::string& config_file) {
    file_name = config_file;
    file = fopen(file_name.c_str(), "r");
    if (!file)
        throw std::runtime_error("File is not found");
    yaml_parser_initialize(&parser);
    yaml_parser_set_input_file(&parser, file);
}

PipelineParser::Pipeline::Pipeline() {
    table.resize(charactreistics_count);
    for (int i = 0; i < charactreistics_count; ++i)
        table[i] = "-";
    start_time = omp_get_wtime();
}

PipelineParser::Pipeline
        PipelineParser::parse_pipeline(yaml_parser_t* parser) {
    yaml_event_t event;
    Pipeline pipeline;
    std::string attr, val;
    std::map <std::string, std::string> command;
    do {
        if (!yaml_parser_parse(parser, &event)) {
            printf("Parser error %d\n", parser->error);
            throw std::runtime_error("Parser error: " +
                std::to_string(parser->error));
        }
        switch (event.type) {
        case YAML_MAPPING_START_EVENT:
            command = std::map <std::string, std::string>();
            break;
        case YAML_MAPPING_END_EVENT:
            pipeline.commands.push_back(command);
            break;
        case YAML_SCALAR_EVENT:
            if (attr == "")
                attr = (const char*)event.data.scalar.value;
            else
                val = (const char*)event.data.scalar.value;
            break;
        case YAML_NO_EVENT:
        case YAML_SEQUENCE_END_EVENT:
        case YAML_DOCUMENT_START_EVENT:
        case YAML_DOCUMENT_END_EVENT:
            break;
        default:
            throw std::runtime_error("Error while parsing");
        }
        if (attr != "" && val != "") {
            std::cout << "command: attr: " << attr
                        << " --- val: " << val << std::endl;
            command[attr] = val;
            attr = val = "";
        }
    } while (event.type != YAML_SEQUENCE_END_EVENT);
    return pipeline;
}

void PipelineParser::parse() {
    yaml_event_t event;
    std::string str;
    do {
        if (!yaml_parser_parse(&parser, &event)) {
            printf("Parser error %d\n", parser.error);
            throw std::runtime_error("Parser error: " +
                std::to_string(parser.error));
        }
        switch (event.type) {
        case YAML_NO_EVENT:
        case YAML_MAPPING_START_EVENT:
        case YAML_MAPPING_END_EVENT:
        case YAML_SEQUENCE_END_EVENT:
        case YAML_DOCUMENT_START_EVENT:
        case YAML_DOCUMENT_END_EVENT:
        case YAML_STREAM_START_EVENT:
        case YAML_STREAM_END_EVENT:
            break;
        case YAML_SEQUENCE_START_EVENT:
            {
                std::cout << "started func" << std::endl;
                Pipeline pipeline = parse_pipeline(&parser);
                pipeline.table[0] = pipeline.name = str;
                pipelines.emplace_back(pipeline);
                std::cout << "pushed pipeline " <<
                            pipeline.name << std::endl;
                std::cout << "ended func" << std::endl;
                break;
            }
        case YAML_SCALAR_EVENT:
            str = (const char*)event.data.scalar.value;
            break;
        default:
            throw std::runtime_error("Error while parsing");
        }
    } while (event.type != YAML_STREAM_END_EVENT
            || event.type == YAML_NO_EVENT);
    yaml_event_delete(&event);
}

void PipelineParser::launch() {
    parse();
    std::cout << "Pipelines count: " << pipelines.size() << std::endl;
    for (auto& p : pipelines) {
        std::cout << "Starting execution of pipeline \""
                    << p.name << "\"" << std::endl;
        p.launch();
        std::cout << "Finished execution of pipeline \""
                    << p.name << "\"" << std::endl;
    }
}

void PipelineParser::Pipeline::launch() {
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
    std::cout << "Commands count: " << commands.size() << std::endl;
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
            std::string count_str = get_param_no_throw(command, "count");
            std::string subtype = get_param_no_throw(command, "subtype");
            int count = 0;
            if (count_str == "_no_parameter")
                count = 1;
            else
                count = std::stoi(count_str);
            if (coarsening_type == "matching") {
                if (type == "random") {
                    for (int i = 0; i < count; ++i) {
                        graph = graph_coarsening(graph,
                                    [](const CSR<double>& graph) -> Matching {
                            return random_matching<double>(graph);
                        });
                        std::cout << "iteration: " << i << " n: " << graph.n
                                << " m: " << graph.edges.size() << std::endl;
                    }
                } else if (type == "hard") {
                    for (int i = 0; i < count; ++i) {
                        graph = graph_coarsening(graph,
                                [](const CSR<double>& graph) -> Matching {
                            return hard_matching<double>(graph);
                            });
                        std::cout << "iteration: " << i << " n: " << graph.n
                                << " m: " << graph.edges.size() << std::endl;
                    }
                } else if (type == "edmonds") {
                    for (int i = 0; i < count; ++i) {
                        graph = graph_coarsening(graph,
                                    [](const CSR<double>& graph) -> Matching {
                            return edmonds<double>(graph);
                            });
                        std::cout << "iteration: " << i << " n: " << graph.n
                                << " m: " << graph.edges.size() << std::endl;
                    }
                } else if (type == "gpa") {
                    if (subtype == "random") {
                        for (int i = 0; i < count; ++i) {
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
                        for (int i = 0; i < count; ++i) {
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
                        for (int i = 0; i < count; ++i) {
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
                        for (int i = 0; i < count; ++i) {
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
                        for (int i = 0; i < count; ++i) {
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
                        for (int i = 0; i < count; ++i) {
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
                        for (int i = 0; i < count; ++i) {
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
                        for (int i = 0; i < count; ++i) {
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
                    for (int i = 0; i < count; ++i) {
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
            try {
                std::string chars = get_param(command, "evaluate");
                if (chars == "pipeline_time") {
                    table[1] = std::to_string(omp_get_wtime() - start_time);
                } else if (chars == "vertexes") {
                    table[2] = std::to_string(graph.n);
                } else if (chars == "edges") {
                    table[3] = std::to_string(graph.edges.size());
                } else if (chars == "avg_vertex_degree") {
                    double ans = static_cast<double>(graph.edges.size())
                                                                / graph.n;
                    table[4] = std::to_string(ans);
                } else if (chars == "max_vertex_weight") {
                    double max_weight = 0;
                    for (int i = 0; i < graph.n; ++i) {
                        double current_weight = 0;
                        for (int j = graph.offset[i];
                                    j < graph.offset[i+1]; ++j)
                            current_weight += graph.weights[j];
                        max_weight = std::max(max_weight, current_weight);
                    }
                    table[5] = std::to_string(max_weight);
                } else if (chars == "graph_diameter") {
                    table[6] = std::to_string(graph_diameter(graph));
                } else if (chars == "graph_radius") {
                    table[7] = std::to_string(graph_radius(graph));
                } else if (chars == "vertexes_in_scc") {
                    std::vector <int> components;
                    find_strongly_connected_components(&components, graph);
                    std::map <int, int> m;
                    for (int comp : components)
                        ++m[comp];
                    int sum = 0;
                    for (auto& comp : m)
                        sum += comp.second;
                    double ans = static_cast<double>(sum) / m.size();
                    table[8] = std::to_string(ans);
                } else if (chars == "bridges") {
                    table[9] = std::to_string(count_bridges(graph));
                } else if (chars == "joint_points") {
                    table[10] = std::to_string(count_joint_points(graph));
                } else if (chars == "avg_eccentricity") {
                    auto ecc = vertexes_eccentricity(graph);
                    double ecc_sum = std::accumulate(begin(ecc), end(ecc), 0);
                    double ans = static_cast<double>(ecc_sum) / graph.n;
                    table[11] = std::to_string(ans);
                } else if (chars == "cost_mst") {
                    table[12] = std::to_string(
                                    get_cost_of_minimal_spanning_tree(graph));
                } else {
                    throw std::runtime_error("Unknown characteristic"
                        "for evaluation: " + chars);
                }
                std::cout << "Finished evaluate command" << std::endl;
            } catch (std::bad_alloc& ba) {
                std::cerr << ba.what() << std::endl;
                std::cout << "Failed evaluate command" << std::endl;
            }
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
        } else {
            std::stringstream s;
            s << std::endl;
            for (auto& a : command)
                s << " - " << a.first << ": " << a.second << std::endl;
            throw std::runtime_error("Unknown command" + s.str());
        }
    }
}

PipelineParser::~PipelineParser() {
    yaml_parser_delete(&parser);
    fclose(file);
}
