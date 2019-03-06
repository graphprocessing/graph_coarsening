// Copyright [year] <Copyright Owner>
#ifndef MODULES_PIPELINES_INCLUDE_PARSER_H_
#define MODULES_PIPELINES_INCLUDE_PARSER_H_
#include "../../pch/include/precomp.h"

class PipelineParser {
 public:
    PipelineParser() = delete;
    explicit PipelineParser(const std::string& config_file);
    ~PipelineParser();
    void launch();
 private:
    void parse();
    std::string file_name;
    FILE* file;
    yaml_parser_t parser;
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
    Pipeline parse_pipeline(yaml_parser_t* parser);
    std::vector <Pipeline> pipelines;
};

#endif  // MODULES_PIPELINES_INCLUDE_PARSER_H_
