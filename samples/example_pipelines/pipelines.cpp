// Copyright [year] <Copyright Owner>
#include "modules/pch/include/precomp.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Please, specify .yaml file" << std::endl;
        return 1;
    }
    PipelineParser p(argv[1]);
    p.launch(PipelineParser::Mode::Sequential);
    return 0;
}
