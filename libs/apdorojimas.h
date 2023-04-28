#pragma once

#include "studentas.h"
#include "lib.h"

void ivesti_ranka();
void generuoti_failus();
void pildyti(Studentas& , bool& , int );
void spausdinti(const Studentas );

template<typename C, typename T = typename C::value_type>
void isvesti_faila(C const& grupe, string failoPav) {
    char eilute[100];
    string output = "";

    for (auto& i : grupe) {
        sprintf(eilute, "%-20s%-20s%-20.2f%-20.2f\n", i.vardas().c_str(), i.pavarde().c_str(), i.galutinis_vid(), i.galutinis_med());
        output += eilute;
    }

    sprintf(eilute, "%-20s%-20s%-20s%-20s", "Vardas", "Pavarde", "Galutinis (vid.)", "Galutinis (med.)");

    ofstream fout(failoPav + ".txt");
    fout << eilute << endl << string(80, '-') << endl << output;
    fout.close();
}

void skaityti_faila();

template<typename C, typename T = typename C::value_type>
void dalinimas_1(C& grupe, C& vargsai, C& protingi) {
    auto splitItr = find_if(grupe.begin(), grupe.end(), [](Studentas& stud) {return stud.galutinis_vid() >= 5;});
    vargsai.assign(grupe.begin(), splitItr);
    protingi.assign(splitItr, grupe.end());
    grupe.clear();
}

void dalinimas_2(vector<Studentas>& , vector<Studentas>& );