// Copyright [year] <Copyright Owner>
#ifndef MODULES_PIPELINES_INCLUDE_PIPELINE_PARSER_H_
#define MODULES_PIPELINES_INCLUDE_PIPELINE_PARSER_H_
#include "../../pch/include/precomp.h"

class PipelineParser {
 public:
    PipelineParser() = delete;
    explicit PipelineParser(const std::string& file_name);
    ~PipelineParser() = default;
    enum class Mode {
        Sequential, Parallel
    };
    void launch(Mode mode = Mode::Sequential);
 private:
    void parse();
    YAMLParser::Value yaml_pipeline;
    struct Pipeline {
        static const int charactreistics_count = 13;
        std::string name;
        CSR <double> graph;
        std::vector <std::map <std::string, std::string>> commands;
        std::vector <std::string> table;
        double start_time;
        void launch();
        Pipeline();
    };
    std::vector <Pipeline> pipelines;
};

#endif  // MODULES_PIPELINES_INCLUDE_PIPELINE_PARSER_H_
