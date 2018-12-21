// Copyright [year] <Copyright Owner>
#include "../pch/include/precomp.h"
#include "../pipelines/prepare.h"
#include "../pipelines/launch.h"

int main(int argc, char** argv) {
    std::cout << "pipelines" << std::endl;
    Pipeline::prepare();
    Pipeline::launch();
    std::cout << "main" << std::endl;
    // Timer sample
    std::cout << std::fixed;
    std::cout << "Execution time for washington_test (n = 2): "
                << Timer::calculate(washington_test, 2, false)
                << " s" << std::endl << std::endl;
    std::cout << "Execution time for washington_test (n = 1e6): "
                << Timer::calculate(washington_test,
                    1000000, false)
                << " s" << std::endl << std::endl;
    return 0;
}
