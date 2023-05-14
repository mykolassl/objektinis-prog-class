#include "gtest/gtest.h"
#include "pagalbines_funk.h"
#include "apdorojimas.h"
#include <cmath>

TEST(GalutinioBaloSkaiciavimas, GalutinisVidurkis) {
    vector<int> pazymiai_1 = {4, 8, 10, 6, 8, 7};
    vector<int> pazymiai_2 = {1, 2, 5, 4, 3, 8};

    EXPECT_EQ(7.17, round(apskaiciuoti_vidurki(pazymiai_1) * 100.0) / 100.0);
    EXPECT_FALSE(apskaiciuoti_vidurki(pazymiai_2) == 2.5);
}

TEST(GalutinioBaloSkaiciavimas, GalutinisMediana) {
    vector<int> pazymiai_1 = {5, 8, 10, 6, 8, 7};
    vector<int> pazymiai_2 = {1, 2, 5, 4, 3, 8};

    EXPECT_EQ(7.5, apskaiciuoti_mediana(pazymiai_1));
    EXPECT_FALSE(apskaiciuoti_mediana(pazymiai_2) == 8);
}