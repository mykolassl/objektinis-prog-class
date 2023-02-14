#include "lib.h"

const int MAX_PAZ_SK = 10;

struct Studentas {
    string vardas = "", pavarde = "";
    int ndKiekis = 0;
    int* ndPazymiai = nullptr;
    int egzPazymys = 0;
};

void pildyti(Studentas& , bool& );
void spausdinti(Studentas , char );
double apskaiciuoti_vidurki(Studentas );
double apskaiciuoti_mediana(Studentas );

int main() {
    int maxStudKiekis = 1, studKiekis = 0;
    char skBudas;   // Galutinio rezultato skaiciavimo budas - igyja 'v' reiksme, jei skaiciuojamas vidurkis, jei mediana -'m'. 
    bool arTesti = true;

    Studentas* grupe = new Studentas [maxStudKiekis];

    while (arTesti) {
        pildyti(grupe[studKiekis], arTesti);
        if (!arTesti) break;
        studKiekis++;

        if (studKiekis >= maxStudKiekis) {
            maxStudKiekis *= 2;

            Studentas* temp = new Studentas [maxStudKiekis];
            copy(grupe, grupe + studKiekis, temp);
            delete [] grupe;

            grupe = new Studentas [maxStudKiekis];
            copy(temp, temp + studKiekis, grupe);
            delete [] temp;
        } 
    }

    cout << "Iveskite studentu galutinio balo skaiciavimo buda (v - vidurkis, m - mediana): "; cin >> skBudas;

    while (skBudas != 'v' && skBudas != 'm') {
        cout << "Neteisinga ivestis, bandykite dar karta: ";

        cin.clear();
        cin.ignore(INT_MAX, '\n');

        cin >> skBudas;
    }

    cout << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis " << (skBudas == 'v' ? "(vid.)" : "(med.)") << endl;
    cout << string(50, '-') << endl; 

    for (int i = 0; i < studKiekis; i++) spausdinti(grupe[i], skBudas);

    for (int i = 0; i < studKiekis; i++) delete [] grupe[i].ndPazymiai;
    delete [] grupe;

    return 0;
}

void pildyti(Studentas& stud, bool& arTesti) {
    string vardas, pavarde;
    
    cout << "Iveskite studento varda bei pavarde: "; cin >> vardas >> pavarde;

    if (vardas == "stop" && pavarde == "stop") {
        arTesti = false;
        cout << "Studentu duomenu ivestis stabdoma" << endl;
        return;
    }

    cin.ignore(80, '\n');
    cin.clear();

    stud.vardas = vardas; 
    stud.pavarde = pavarde;

    int pazymiai[MAX_PAZ_SK], pazymiuKiekis = 0;

    cout << "Iveskite iki " << MAX_PAZ_SK << " pazymiu: ";

    for (int j = 0; j < MAX_PAZ_SK; j++) {
        int pazymys;
        
        while ( !(cin >> pazymys) || pazymys < -1 || pazymys > 10) {
            cout << "Neteisinga ivestis, bandykite dar karta: ";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }

        if (pazymys == -1) {
            cout << "Pazymiu ivestis stabdoma" << endl;
            break;
        } 

        pazymiai[pazymiuKiekis] = pazymys;
        pazymiuKiekis++;

        if (pazymiuKiekis >= MAX_PAZ_SK) break;
    }

    stud.ndPazymiai = new int [pazymiuKiekis];
    copy(pazymiai, pazymiai + pazymiuKiekis, stud.ndPazymiai);
    stud.ndKiekis = pazymiuKiekis;

    int egzPazymys;

    cout << "Iveskite egzamino pazymi: ";

    while ( !(cin >> egzPazymys) || egzPazymys < 0 || egzPazymys > 10) {
        cout << "Neteisinga ivestis, bandykite dar karta: ";
        cin.clear();
        cin.ignore( INT_MAX, '\n' );
    }

    stud.egzPazymys = egzPazymys;

    cout << "Studento duomenys sekmingai ivesti." << endl << endl;
}

void spausdinti(Studentas stud, char skBudas) {
    cout << stud.vardas << setw(15) << stud.pavarde << setw(20);

    double galutinis;

    if (skBudas == 'v') galutinis = 0.4 * apskaiciuoti_vidurki(stud) + 0.6 * stud.egzPazymys;
    else galutinis = 0.4 * apskaiciuoti_mediana(stud) + 0.6 * stud.egzPazymys;

    cout << fixed << setprecision(2) << galutinis << setw(5) << endl;
}

double apskaiciuoti_vidurki(Studentas stud) {
    int sum = 0;

    for (int i = 0; i < stud.ndKiekis; i++) sum += stud.ndPazymiai[i];

    return (double)sum / stud.ndKiekis;
}

double apskaiciuoti_mediana(Studentas stud) {
    for (int i = 0; i < stud.ndKiekis; i++) {
        for (int j = 0; j < stud.ndKiekis; j++) {
            if (stud.ndPazymiai[i] < stud.ndPazymiai[j]) swap(stud.ndPazymiai[i], stud.ndPazymiai[j]);
        }
    }

    if (stud.ndKiekis % 2 == 1) {
        return stud.ndPazymiai[(int)stud.ndKiekis / 2];
    } else {
        return (stud.ndPazymiai[stud.ndKiekis / 2] + stud.ndPazymiai[stud.ndKiekis / 2 - 1]) / 2.0;
    }
}