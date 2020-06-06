/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RNGGenerator.cpp
 * Author: D000M
 * 
 * Created on June 5, 2020, 2:45 PM
 */

#include "RNGGenerator.h"
long long startSeed;

std::mt19937& globalRNG() {
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    setSeed(seed);
    static std::mt19937 u{seed};
    return u;
}

void randomize() {
    static std::random_device rd{};
    globalRNG().seed(rd());
}

int getRandomInteger(int from, int to) {
    static std::uniform_int_distribution<> d{};
    using param_t = decltype(d)::param_type;
    return d(globalRNG(), param_t(from, to));
}

double getRandomDouble(double from, double to) {
    static std::uniform_real_distribution<> d{};
    using param_t = decltype(d)::param_type;
    return d(globalRNG(), param_t(from, to));
}

void setSeed(long long seed) {
    startSeed = seed;
}
long long getSeed() {
    return startSeed;
}
