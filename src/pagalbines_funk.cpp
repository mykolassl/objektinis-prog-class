#include "../libs/lib.h"
#include "../libs/studentas.h"

void generuoti(Studentas& stud) {
    random_device r_d;
    mt19937 mt(r_d());
    uniform_int_distribution<int> dist(1, 10);

    for (auto& i : stud.ndPazymiai) i = dist(mt);

    stud.egzPazymys = dist(mt);
}

double apskaiciuoti_vidurki(Studentas stud) {
    int sum = accumulate(stud.ndPazymiai.begin(), stud.ndPazymiai.end(), 0);
    
    return (double)sum / stud.ndPazymiai.size();
}

double apskaiciuoti_mediana(Studentas stud) {
    sort(stud.ndPazymiai.begin(), stud.ndPazymiai.end());

    if (stud.ndPazymiai.size() % 2 == 1) {
        return stud.ndPazymiai[stud.ndPazymiai.size() / 2];
    } else {
        return (stud.ndPazymiai[stud.ndPazymiai.size() / 2] + stud.ndPazymiai[stud.ndPazymiai.size() / 2 - 1]) / 2.0;
    }
}

bool palyginti_studentus(const Studentas stud1, const Studentas stud2) {
    return stud2.vardas > stud1.vardas;
}