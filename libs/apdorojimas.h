#pragma once

#include "studentas.h"

void skaityti_faila();
void ivesti_ranka();
void isvesti_faila(vector<Studentas>& , string );
void generuoti_failus();
void pildyti(Studentas& , bool& , int );
void spausdinti(const Studentas );
void dalinimas_1(vector<Studentas>& , vector<Studentas>& , vector<Studentas>& );
void dalinimas_2(vector<Studentas>& , vector<Studentas>& );