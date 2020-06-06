/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RNGGenerator.h
 * Author: D000M
 *
 * Created on June 5, 2020, 2:45 PM
 */

#ifndef RNGGENERATOR_H
#define RNGGENERATOR_H

#include <random>
#include <functional>
#include <chrono>
#include <iostream>

std::mt19937& globalRNG();

void randomize();

int getRandomInteger(int from, int to);

double getRandomDouble(double from, double to);

void setSeed(long long seed);
long long getSeed();

#endif /* RNGGENERATOR_H */

