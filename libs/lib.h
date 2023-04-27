#pragma once

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <random>
#include <numeric>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>
#include <vector>
#include <deque>
#include <list>
#include <concepts>

// ************* I/O *************
using std::cout;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::stringstream;
using std::endl;
using std::left;
using std::right;
using std::setw;
using std::fixed;
using std::setprecision;

// ************* Algoritmai *************
using std::accumulate;
using std::sort;
using std::swap;
using std::copy;
using std::find_if;

// ************* Konteineriai *************
using std::vector;
using std::deque;
using std::string;

// ************* Pagalbiniai *************
using std::to_string;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

// ************* Namespaces *************
using namespace std::chrono;

// ************* Concepts **************
template<typename T>
concept Konteineris = std::same_as<T, std::vector<typename T::value_type>>
    || std::same_as<T, std::list<typename T::value_type>>
    || std::same_as<T, std::deque<typename T::value_type>>; 