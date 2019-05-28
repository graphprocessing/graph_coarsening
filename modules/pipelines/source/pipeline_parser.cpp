// Copyright [year] <Copyright Owner>
#include "../../pch/include/precomp.h"

PipelineParser::PipelineParser(const std::string& file_name) :
                yaml_pipeline(YAMLParser(file_name).parse()) {}

PipelineParser::Pipeline::Pipeline(std::vector <Pipeline> *pipelines) :
    pipelines(pipelines) {
    table.resize(charactreistics_count);
    for (int i = 0; i < charactreistics_count; ++i)
        table[i] = "-";
}

void PipelineParser::parse() {
    YAMLParser::Sequence raw_pipelines = yaml_pipeline.get_mapping().get_map()
                            .find("pipelines")->second.get_sequence();
    for (const YAMLParser::Value &raw_pipeline : raw_pipelines) {
        Pipeline result_pipeline(&pipelines);
        result_pipeline.name = raw_pipeline.get_mapping().
                            get_map().begin()->first;
        YAMLParser::Sequence raw_commands = raw_pipeline.get_mapping().
                            get_map().begin()->second.get_sequence();
        for (YAMLParser::Value raw_command : raw_commands) {
            std::map <std::string, std::string> command;
            for (const std::pair <std::string, YAMLParser::Value> &attr :
                            raw_command.get_mapping().get_map()) {
                command.emplace(attr.first, attr.second.get_string());
            }
            result_pipeline.commands.emplace_back(command);
        }
        pipelines.emplace_back(result_pipeline);
    }
    if (yaml_pipeline.get_mapping().has_key("wrappers")) {
        YAMLParser::Sequence raw_wrappers = yaml_pipeline.get_mapping().
                                get_map().find("wrappers")->second.
                                get_sequence();
        for (const YAMLParser::Value &raw_wrapper : raw_wrappers) {
            Pipeline result_wrapper(&pipelines);
            result_wrapper.name = raw_wrapper.get_mapping().
                                get_map().begin()->first;
            YAMLParser::Sequence raw_commands = raw_wrapper.get_mapping().
                                get_map().begin()->second.get_sequence();
            for (YAMLParser::Value raw_command : raw_commands) {
                std::map <std::string, std::string> command;
                for (const std::pair <std::string, YAMLParser::Value> &attr :
                                raw_command.get_mapping().get_map()) {
                    command.emplace(attr.first, attr.second.get_string());
                }
                result_wrapper.commands.emplace_back(command);
            }
            pipelines.emplace_back(result_wrapper);
        }
    }
    YAMLParser::Sequence executable_pipelines = yaml_pipeline.get_mapping()
                            .get_map().find("run")->second.get_sequence();
    for (const YAMLParser::Value &executable_pipeline : executable_pipelines) {
        run_list.push_back(executable_pipeline.get_string());
    }
}

void PipelineParser::call(const std::string &pipeline_name) {
    for (Pipeline &pipeline : pipelines) {
        if (pipeline.name == pipeline_name) {
            std::cout << "Starting execution of pipeline \""
                    << pipeline_name << "\"" << std::endl;
            pipeline.launch();
            std::cout << "Finished execution of pipeline \""
                    << pipeline_name << "\"" << std::endl;
            return;
        }
    }
    throw std::runtime_error("Unable to find pipeline " + pipeline_name);
}

void PipelineParser::launch(Mode mode) {
    parse();
    std::cout << "Pipelines count: " << pipelines.size() << std::endl;
    std::cout << "Running pipelines count: " << run_list.size() << std::endl;
    if (mode == Mode::Sequential) {
        for (unsigned i = 0; i < run_list.size(); ++i) {
            call(run_list[i]);
        }
    } else if (mode == Mode::Parallel) {
        #pragma omp parallel for
        for (int i = 0; i < static_cast<int>(run_list.size()); ++i) {
            call(run_list[i]);
        }
    } else {
        throw std::runtime_error("Unknown mode of pipeline running");
    }
}

void PipelineParser::Pipeline::launch() {
    std::cout << "Commands count: " << commands.size() << std::endl;
    start_time = omp_get_wtime();
    perform_commands();
}
