#pragma once

#include "lib.h"

class Generatorius {
private:
    random_device m_RandDevice;
    mt19937 m_Mt;
    uniform_int_distribution<int> m_Distribution;

public:
    Generatorius()
        : m_Mt(m_RandDevice()), m_Distribution(1, 10) {}

    Generatorius(int virsus, int apacia)
        : m_Mt(m_RandDevice()), m_Distribution(virsus, apacia) {}

    void generuoti_balus(vector<int>& pazymiai, int& egzaminas) {
        std::transform(pazymiai.begin(), pazymiai.end(), pazymiai.begin(), [&](int& p) { p = m_Distribution(m_Mt); });
        egzaminas = m_Distribution(m_Mt);
    }
};