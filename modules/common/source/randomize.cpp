// Copyright [year] <Copyright Owner>
#include <functional>
#include <vector>
#include <random>
#include <algorithm>
#include "../include/randomize.h"

static std::random_device rd;
static std::mt19937 generator(rd());

static std::function <int (int)> randomize_distribution[] = {
    [&](int a) {
        return std::uniform_int_distribution<int>(0, a - 1)(generator);
    },
    [&](int a) {
        return std::normal_distribution<float>(0, a - 1)(generator);
    }
};

bool randomize_permutation(std::vector <int>* permutation, unsigned dist) {
    if (dist > sizeof(randomize_distribution))
        return false;
    std::random_shuffle(permutation->begin(), permutation->end(),
        randomize_distribution[dist]);
    return true;
}