// Copyright [year] <Copyright Owner>
#ifndef MODULES_COMMON_INCLUDE_EXPORT_H_
#define MODULES_COMMON_INCLUDE_EXPORT_H_
#include "../../pch/include/precomp.h"

template <typename WeightType>
bool export_for_visualization(const Graph<WeightType>& graph,
                              const std::string& file) {
    std::ofstream out(file);
    if (!out.is_open())
        return false;
    // out << std::fixed;
    std::vector <std::pair <int, WeightType>> neighbours;
    for (int i = 0; i < graph.n; ++i) {
        neighbours.clear();
        graph.get_neighbours(&neighbours, i, i);
        for (unsigned j = 0; j < neighbours.size(); ++j)
            out << i << " " << neighbours[j].first << " "
                    << neighbours[j].second << std::endl;
    }
    out.close();
    return true;
}

void get_temp_filename(char *buffer);

#endif  // MODULES_COMMON_INCLUDE_EXPORT_H_
