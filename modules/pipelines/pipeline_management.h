// Copyright [year] <Copyright Owner>
#ifndef MODULES_PIPELINES_PIPELINE_MANAGEMENT_H_
#define MODULES_PIPELINES_PIPELINE_MANAGEMENT_H_
#ifndef COMPILER_NAME
#define COMPILER_NAME "unknown"
#endif  // COMPILER_NAME
#include "../pch/include/precomp.h"

namespace Pipeline {
    std::vector <std::function <std::string(const std::string&)>> pipelines;
    std::vector <std::string> pipeline_names;
    std::vector <std::function
            <std::string(const std::string&,  // graph before pipeline (file)
                         const std::string&,  // graph after pipeline (file)
                         const std::string&,  // pipeline name
                         const double)>>      // pipeline time
                            results_evaluators;
    bool launch(const std::string& graph_file) {
        for (auto& evaluator : results_evaluators) {
            int i = 0;
            for (auto pipeline : pipelines) {
                std::string new_file;
                // Call of pipeline function
                auto fu = [&]() {
                    std::cout << "processing "
                                << graph_file << std::endl;
                    new_file = pipeline(graph_file);
                    std::cout << "done processing "
                                << graph_file << std::endl;
                };
                // Export graph characteristics to file
                evaluator(graph_file, new_file,
                            pipeline_names[i++], Timer::calculate(fu));
            }
        }
        return true;
    }
}  // namespace Pipeline

#endif  // MODULES_PIPELINES_PIPELINE_MANAGEMENT_H_
