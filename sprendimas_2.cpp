#include "lib.h"

struct Studentas {
    string vardas = "", pavarde = "";
    int* ndPazymiai = nullptr;
    int egzPazymys = 0;
};

void pildyti(Studentas& , bool& , int );
void spausdinti(Studentas , char , int);
void generuoti(Studentas& , int );
double apskaiciuoti_vidurki(Studentas , int );
double apskaiciuoti_mediana(Studentas , int );

int main() {
    srand(time(NULL));

    int maxStudKiekis = 1, studKiekis = 0, ndKiekis = 0;
    char skBudas;   // Galutinio rezultato skaiciavimo budas - igyja 'v' reiksme, jei skaiciuojamas vidurkis, jei mediana -'m'. 
    bool arTesti = true;

    cout << "Iveskite namu darbu skaiciu, kuris buvo skirtas studentams: ";

    while (!(cin >> ndKiekis) || ndKiekis <= 0) {
        cout << "Neteinga ivestis, bandykite dar karta: ";

        cin.clear();
        cin.ignore(80, '\n');
    }

    Studentas* grupe = new Studentas [maxStudKiekis];

    while (arTesti) {
        pildyti(grupe[studKiekis], arTesti, ndKiekis);
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
        cin.ignore(80, '\n');

        cin >> skBudas;
    }

    cout << setw(15) << left << "Vardas" << setw(15) << "Pavarde" << "Galutinis " << (skBudas == 'v' ? "(vid.)" : "(med.)") << endl;
    cout << string(50, '-') << endl; 

    for (int i = 0; i < studKiekis; i++) spausdinti(grupe[i], skBudas, ndKiekis);

    for (int i = 0; i < studKiekis; i++) delete [] grupe[i].ndPazymiai;
    delete [] grupe;

    return 0;
}

void pildyti(Studentas& stud, bool& arTesti, int ndKiekis) {
    // ************** Vardas ir pavarde **************
    string vardas, pavarde;
    
    cout << "Iveskite studento varda bei pavarde: "; cin >> vardas >> pavarde;

    if (vardas == "stop" && pavarde == "stop") {
        arTesti = false;
        cout << "Studentu duomenu ivestis stabdoma" << endl;

        cin.ignore(80, '\n');
        cin.clear();
        
        return;
    }

    cin.ignore(80, '\n');
    cin.clear();

    stud.vardas = vardas; 
    stud.pavarde = pavarde;

    // ************** Namu darbai **************
    stud.ndPazymiai = new int [ndKiekis] { 0 };

    // Atsitiktinis generavimas
    char arGeneruoti;

    cout << "Ar norite atsitiktinai sugeneruoti sio studento pazymius? (t - taip, n - ne) "; cin >> arGeneruoti;
    while (arGeneruoti != 't' && arGeneruoti != 'n') {
        cout << "Neteisinga ivestis, bandykite dar karta: ";
        
        cin.clear();
        cin.ignore(80, '\n');

        cin >> arGeneruoti;
    }

    cin.clear();
    cin.ignore(80, '\n');

    if (arGeneruoti == 't') {
        generuoti(stud, ndKiekis);
        cout << "Studento namu darbu bei egzamino rezultatai sekmingai sugeneruoti." << endl << endl;
        return;
    } 

    cout << "Iveskite iki " << ndKiekis << " pazymiu: ";

    for (int i = 0; i < ndKiekis; i++) {
        int pazymys;
        
        while ( !(cin >> pazymys) || pazymys < -1 || pazymys > 10) {
            cout << "Neteisinga ivestis, bandykite dar karta: ";

            cin.clear();
            cin.ignore(80, '\n');
        }

        if (pazymys == -1) {
            cout << "Pazymiu ivestis stabdoma" << endl;
            break;
        } 

        stud.ndPazymiai[i] = pazymys;
    }

    cin.ignore(80, '\n');
    cin.clear();

    // ************** Egzaminas **************
    int egzPazymys;

    cout << "Iveskite egzamino pazymi: ";

    while ( !(cin >> egzPazymys) || egzPazymys < 0 || egzPazymys > 10) {
        cout << "Neteisinga ivestis, bandykite dar karta: ";

        cin.clear();
        cin.ignore(80, '\n');
    }

    stud.egzPazymys = egzPazymys;

    cout << "Studento duomenys sekmingai ivesti." << endl << endl;
}

void spausdinti(Studentas stud, char skBudas, int ndKiekis) {
    cout << setw(15) << stud.vardas << setw(15) << stud.pavarde << setw(20);

    double galutinis;

    if (skBudas == 'v') galutinis = 0.4 * apskaiciuoti_vidurki(stud, ndKiekis) + 0.6 * stud.egzPazymys;
    else galutinis = 0.4 * apskaiciuoti_mediana(stud, ndKiekis) + 0.6 * stud.egzPazymys;

    cout << fixed << setprecision(2) << galutinis << setw(5) << endl;
}

void generuoti(Studentas& stud, int ndKiekis) {
    for (int i = 0; i < ndKiekis; i++) {
        stud.ndPazymiai[i] = (double)rand() / RAND_MAX * 10 + 1;
    }

    stud.egzPazymys = (double)rand() / RAND_MAX * 10 + 1;
}

double apskaiciuoti_vidurki(Studentas stud, int ndKiekis) {
    int sum = 0;

    for (int i = 0; i < ndKiekis; i++) sum += stud.ndPazymiai[i];

    return (double)sum / ndKiekis;
}

double apskaiciuoti_mediana(Studentas stud, int ndKiekis) {
    for (int i = 0; i < ndKiekis; i++) {
        for (int j = 0; j < ndKiekis; j++) {
            if (stud.ndPazymiai[i] < stud.ndPazymiai[j]) swap(stud.ndPazymiai[i], stud.ndPazymiai[j]);
        }
    }

    if (ndKiekis % 2 == 1) {
        return stud.ndPazymiai[(int)ndKiekis / 2];
    } else {
        return (stud.ndPazymiai[ndKiekis / 2] + stud.ndPazymiai[ndKiekis / 2 - 1]) / 2.0;
    }
}