/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Utils.h
 * Author: D000M
 *
 * Created on June 5, 2020, 4:35 PM
 */

#ifndef UTILS_H
#define UTILS_H

#include <sstream>
#include <string>

template<typename T>
std::string toString(T obj) {
    std::stringstream ss;
    ss << obj;
    return ss.str();
}

#endif /* UTILS_H */

