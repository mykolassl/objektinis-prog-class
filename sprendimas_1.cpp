#include "lib.h"

struct Studentas {
    string vardas = "", pavarde = "";
    vector<int> ndPazymiai;
    int egzPazymys = 0;
};

void pildyti(Studentas& , bool& , int );
void spausdinti(const Studentas , char );
void generuoti(Studentas& );
double apskaiciuoti_vidurki(Studentas );
double apskaiciuoti_mediana(Studentas );

int main() {
    srand(time(NULL));

    int ndKiekis = 0;
    char skBudas;   // Galutinio rezultato skaiciavimo budas - igyja 'v' reiksme, jei skaiciuojamas vidurkis, jei mediana -'m'. 
    bool arTesti = true;

    cout << "Iveskite namu darbu skaiciu, kuris buvo skirtas studentams: ";

    while (!(cin >> ndKiekis) || ndKiekis <= 0) {
        cout << "Neteinga ivestis, bandykite dar karta: ";

        cin.clear();
        cin.ignore(80, '\n');
    }

    vector<Studentas> grupe;

    while (arTesti) {
        Studentas temp;
        pildyti(temp, arTesti, ndKiekis);
        if (!arTesti) break;

        grupe.push_back(temp);
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

    for (const auto& i : grupe) spausdinti(i, skBudas);

    grupe.clear();

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
    stud.ndPazymiai.resize(ndKiekis);

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
        generuoti(stud);
        cout << "Studento namu darbu bei egzamino rezultatai sekmingai sugeneruoti." << endl << endl;
        return;
    } 

    cout << "Iveskite iki " << ndKiekis << " pazymiu: ";

    for (auto& i : stud.ndPazymiai) {
        int pazymys;
        
        while (!(cin >> pazymys) || pazymys < -1 || pazymys > 10) {
            cout << "Neteisinga ivestis, bandykite dar karta: ";

            cin.clear();
            cin.ignore(80, '\n');
        }

        if (pazymys == -1) {
            cout << "Pazymiu ivestis stabdoma" << endl;
            break;
        } 

        i = pazymys;
    }

    cin.ignore(80, '\n');
    cin.clear();

    // ************** Egzaminas **************
    int egzPazymys;

    cout << "Iveskite egzamino pazymi: ";

    while (!(cin >> egzPazymys) || egzPazymys < 0 || egzPazymys > 10) {
        cout << "Neteisinga ivestis, bandykite dar karta: ";

        cin.clear();
        cin.ignore(80, '\n');
    }

    stud.egzPazymys = egzPazymys;

    cout << "Studento duomenys sekmingai ivesti." << endl << endl;
}

void spausdinti(const Studentas stud, char skBudas) {
    cout << setw(15) << stud.vardas << setw(15) << stud.pavarde << setw(20);

    double galutinis;

    if (skBudas == 'v') galutinis = 0.4 * apskaiciuoti_vidurki(stud) + 0.6 * stud.egzPazymys;
    else galutinis = 0.4 * apskaiciuoti_mediana(stud) + 0.6 * stud.egzPazymys;

    cout << fixed << setprecision(2) << galutinis << setw(5) << endl;
}

void generuoti(Studentas& stud) {
    for (auto& i : stud.ndPazymiai) i = (double)rand() / RAND_MAX * 10 + 1;

    stud.egzPazymys = (double)rand() / RAND_MAX * 10 + 1;
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