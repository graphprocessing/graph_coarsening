// Copyright [year] <Copyright Owner>
#ifndef MODULES_PIPELINES_LAUNCH_H_
#define MODULES_PIPELINES_LAUNCH_H_
#include <string>
#include <vector>
#include <functional>
#include <fstream>

namespace Pipeline {
    std::vector <function <int()>> pipelines;
    const std::string launch() {
        const std::string file_name = "..\..\..\graph_data\pipeline_";
        std::ofstream out(file_name);
        for (auto f : pipelines) {
            CSR graph;
            graph.read(f());
            // out << data;
        }
        return file_name;
    }
}  // namespace Pipeline

#endif  // MODULES_PIPELINES_LAUNCH_H_
