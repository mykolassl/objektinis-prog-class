#include "lib.h"

const int PAZ_SK = 5;

struct Studentas {
    string vardas = "", pavarde = "";
    int* ndPazymiai = nullptr;
    int egzPazymys = 0;
};

void pildyti(Studentas& );
void spausdinti(Studentas , char );
double apskaiciuoti_vidurki(int* );
int apskaiciuoti_mediana(int *);

int main() {
    int studKiekis;
    char skBudas; // Galutinio rezultato skaiciavimo budas - igyja 'v' reiksme, jei skaiciuojamas vidurkis, jei mediana = 'm'. 
    cout << "Kiek studentu Jusu grupeje ? "; cin >> studKiekis;

    Studentas* grupe = new Studentas [studKiekis];
    for (int i = 0; i < studKiekis; ++i) pildyti(grupe[i]);

    do {
        cout << "Sk reikme " << skBudas << endl;
        cout << "Pasirinkite studentu galutinio pazymio skaiciavimo buda. 'v' - vidurkis, 'm' - mediana: "; cin >> skBudas;
        
        if (skBudas == 'v' || skBudas == 'm') break;
    } while (true);

    cout << "Vardas" << setw(20) << std::setfill(' ') << "Pavarde" << setw(20) << "Galutinis " << (skBudas == 'v' ? "(vid.)" : "(med.)") << setw(20) << "Egzaminas" << endl;
    cout << "-----------------------------------------------------------------------------" << endl;

    for (int i = 0; i < studKiekis; ++i) spausdinti(grupe[i], skBudas);

    // Atminties atlaisvinimas
    for (int i = 0; i < studKiekis; ++i) delete [] grupe[i].ndPazymiai;
    delete [] grupe;             

    return 0;
}

void pildyti(Studentas& stud) {
    cout << "Iveskite studento varda bei pavarde: "; cin >> stud.vardas >> stud.pavarde;
    cout << "Iveskite " << PAZ_SK << " pazymius: ";

    int pazymiai[PAZ_SK] { 0 }, i = 0, pazymys = -1;

    while (cin >> pazymys && i < PAZ_SK) {
        if (pazymys == 0) break;
        if (pazymys < 0 || pazymys > 10) continue;

            cout << "RAN" << endl;

        pazymiai[i] = pazymys;
        ++i;
    }

    cin.ignore(80, '\n');
    cin.clear();

    stud.ndPazymiai = new int [PAZ_SK];
    copy(pazymiai, pazymiai + PAZ_SK, stud.ndPazymiai);

    cout << "Iveskite egzamino pazymi: "; cin >> stud.egzPazymys;
    cout << "Duomenys sekmingai ivesti." << endl << endl;
}

void spausdinti(Studentas stud, char skBudas) {
    cout << stud.vardas << setw(20) << std::setfill(' ')  << stud.pavarde << setw(20) << std::setfill(' ');

    
    if (skBudas == 'v') cout << apskaiciuoti_vidurki(stud.ndPazymiai) << " "; 
    else cout << apskaiciuoti_mediana(stud.ndPazymiai) << " ";

    cout << setw(20)  << std::setfill(' ') << stud.egzPazymys << endl;
}

double apskaiciuoti_vidurki(int* pazymiai) {
    int sum = 0;

    for (int i = 0; i < PAZ_SK; ++i) {
        sum += pazymiai[i];
    }

    return sum / PAZ_SK * 1.0;
}

int apskaiciuoti_mediana(int* pazymiai) {
    for (int i = 0; i < PAZ_SK; ++i) {
        for (int j = i + 1; j < PAZ_SK; ++j) {
            if(pazymiai[i] > pazymiai[j]) swap(pazymiai[i], pazymiai[j]);
        }
    }

    if (PAZ_SK % 2 == 1) {
        return pazymiai[PAZ_SK / 2];
    } else {
        double sk = (pazymiai[PAZ_SK / 2 - 1] + pazymiai[PAZ_SK / 2]) / 2;
        return sk;
    }
}