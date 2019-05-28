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
    void call(const std::string &pipeline_name);
    YAMLParser::Value yaml_pipeline;
    struct Pipeline {
        static const int charactreistics_count = 13;
        std::string name;
        CSR <double> graph;
        std::vector <std::map <std::string, std::string>> commands;
        std::vector <std::string> table;
        std::vector <Pipeline> *pipelines;
        double start_time;
        void launch();
        void perform_commands();
        std::string evaluate_characteristic(const std::string &characteristic);
        void set_characteristic(const std::string &characteristic);
        Pipeline() = delete;
        explicit Pipeline(std::vector <Pipeline> *pipelines);
        ~Pipeline() = default;
    };
    std::vector <Pipeline> pipelines;
    std::vector <std::string> run_list;
};

#endif  // MODULES_PIPELINES_INCLUDE_PIPELINE_PARSER_H_
