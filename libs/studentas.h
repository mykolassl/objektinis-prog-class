#pragma once

#include <string>
#include <vector>

struct Studentas {
    std::string vardas = "", pavarde = "";
    double galutinis_vid = 0, galutinis_med = 0;
    int egzPazymys = 0;
    std::vector<int> ndPazymiai;
};