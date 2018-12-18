// Copyright [year] <Copyright Owner>
#ifndef MODULES_PIPELINES_LAUNCH_H_
#define MODULES_PIPELINES_LAUNCH_H_
#include <string>
#include <vector>
#include <functional>
#include <fstream>
#include <cstring>

namespace Pipeline {
    std::vector <std::function <std::string(const std::string&)>> pipelines;
    const std::string launch() {
        const std::string file_name =
                std::string("../../../graph_data/pipeline_") +
                std::string(COMPILER_NAME);
        std::ofstream out(file_name);
        for (auto f : pipelines) {
            CSR graph;
            auto temp = f("");
            graph.read(temp);
            // out << data;
        }
        return file_name;
    }
}  // namespace Pipeline

// <build.py> Pipelines declarations
#include "../pipelines/launch.h"
#include "../pipelines/pipeline_sample.h"
// <build.py> End of pipelines declarations
#endif  // MODULES_PIPELINES_LAUNCH_H_
