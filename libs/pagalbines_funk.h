#pragma once

#include "lib.h"

#define DLLExport __declspec(dllexport)

DLLExport void generuoti_faila(int , int );
DLLExport void generuoti_pazymius(vector<int>& , int& );
DLLExport double apskaiciuoti_vidurki(vector<int> );
DLLExport double apskaiciuoti_mediana(vector<int> );