#include "../libs/lib.h"
#include "../libs/studentas.h"
#include "../libs/pagalbines_funk.h"
#include "../libs/apdorojimas.h"
#include "../libs/timer.hpp"

void dalinimas_2(list<Studentas>& grupe, list<Studentas>& protingi) {
    auto splitItr = find_if(grupe.begin(), grupe.end(), [](Studentas& stud) { return stud.galutinis_vid() >= 5; });
    protingi.assign(splitItr, grupe.end());

    grupe.resize(grupe.size() - protingi.size());
}

void pildyti(Studentas& stud, bool& arTesti, int ndKiekis) {
    // ************** Vardas ir pavarde **************
    vector<int> pazymiai;
    string vardas, pavarde;
    int egzPazymys;
    cout << "Iveskite studento varda: "; cin >> vardas;
    stud.vardas(vardas);

    cin.ignore(80, '\n');
    cin.clear();

    if (stud.vardas() == "stop") {
        arTesti = false;
        stud.vardas("");
        cout << "Studentu duomenu ivestis stabdoma" << endl << endl;
        return;
    }

    cout << "Iveskite studento pavarde: "; cin >> pavarde;
    stud.pavarde(pavarde);

    cin.ignore(80, '\n');
    cin.clear();

    // ************** Namu darbai **************
    pazymiai.resize(ndKiekis);

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
        generuoti_pazymius(pazymiai, egzPazymys);
        stud.pazymiai(pazymiai, egzPazymys);
        cout << "Studento namu darbu bei egzamino rezultatai sekmingai sugeneruoti." << endl << endl;
        return;
    } 

    cout << "Iveskite iki " << ndKiekis << " pazymiu: ";

    for (auto& i : pazymiai) {
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

    cout << "Iveskite egzamino pazymi: ";

    while (!(cin >> egzPazymys) || egzPazymys < 0 || egzPazymys > 10) {
        cout << "Neteisinga ivestis, bandykite dar karta: ";

        cin.clear();
        cin.ignore(80, '\n');
    }

    cin.clear();
    cin.ignore(80, '\n');

    stud.vardas(vardas);
    stud.pavarde(pavarde);
    stud.pazymiai(pazymiai, egzPazymys);

    cout << "Studento duomenys sekmingai ivesti." << endl << endl;
}

void skaityti_faila() {
    Timer timer;
    stringstream ssIn;

    int dalinimo_budas;
    cout << "1. Daznu atveju letesnis, panaudoja daugiau atminties." << endl
         << "2. Daznu atveju greitesnis, panaudoja maziau atminties." << endl;
    cout << "Pasirinkite viena is auksciau pateiktu dalinimo budu: "; cin >> dalinimo_budas;
    
    while (dalinimo_budas != 1 && dalinimo_budas != 2) {
        cout << "Neteisinga ivestis, bandykite dar karta: ";

        cin.clear();
        cin.ignore(INT_MAX, '\n');

        cin >> dalinimo_budas;
    }

    string failas;
    int failoIndeksas;
    vector<string> failuSarasas;

    system("dir /b *.txt > sarasas.txt");
    ifstream fsar("sarasas.txt");
    while (getline(fsar, failas)) {
        if (failas != "sarasas.txt") failuSarasas.push_back(failas);
    }
    fsar.close();
    system("del sarasas.txt");

    for (int i = 0; i < failuSarasas.size(); i++) {
        cout << i + 1 << ". " << failuSarasas.at(i) << endl;
    }
    cout << "Iveskite failo numeri is auksciau pateikto saraso: ";
    
    while (true) {
        try {
            cin >> failoIndeksas;

            timer.start();

            ifstream fin;
            fin.exceptions(ifstream::failbit | ifstream::badbit);
            fin.open(failuSarasas.at(failoIndeksas - 1));

            ssIn << fin.rdbuf();
            
            fin.close();

            timer.end();
            timer.print("Failo skaitymas uztruko");

            break;
        } catch (...) {
            cin.clear();
            cin.ignore(80, '\n');
            cout << "Skaicius privalo buti intervale nuo 1 iki " << failuSarasas.size() << ", bandykite dar karta: ";
        }
    }

    // Pazymiu kiekio, iskaitant egzamina, nustatymas.
    string eilute;
    stringstream ssTemp;
    int pazymiuKiekis = 0;

    timer.start();

    getline(ssIn, eilute);
    ssTemp << eilute;

    while (!ssTemp.eof()) {
        string v;
        ssTemp >> v;

        if (v.empty()) continue;

        pazymiuKiekis++;
    }

    pazymiuKiekis -= 2;     // Atimami vardas ir pavarde, kurie buvo nuskaityti pradzioje.

    if (pazymiuKiekis < 2) {
        cout << "Faile turi buti nurodytas bent vienas namu darbu ir egzamino pazymys." << endl;
        return;
    }

    Studentas stud(pazymiuKiekis);

    list<Studentas> grupe, protingi, vargsai;

    while (!ssIn.eof()) {
        ssIn >> stud;      

        ssIn.ignore(INT_MAX, '\n');
        grupe.push_back(stud);
    }

    timer.end();
    timer.print("Failo duomenu apdorojimas uztruko");

    timer.start();

    grupe.sort();
    
    timer.end();
    timer.print("Studentu rikiavimas uztruko");

    timer.start();

    if (dalinimo_budas == 1) dalinimas_1(grupe, vargsai, protingi);
    else dalinimas_2(grupe, protingi);

    timer.end();
    timer.print("Studentu atskyrimas i vargsus ir protingus uztruko");

    timer.start();

    isvesti_faila(dalinimo_budas == 1 ? vargsai : grupe, "vargsai");
    isvesti_faila(protingi, "protingi");

    timer.end();
    timer.print("Vargsu ir protingu isvedimas i du failus uztruko");
    timer.print_end("Is viso failo apdorojimas uztruko");
    
    grupe.clear();
    protingi.clear();
    vargsai.clear();
}

void ivesti_ranka() {
    int ndKiekis = 0;
    bool arTesti = true;

    cout << "Iveskite namu darbu skaiciu, kuris buvo skirtas studentams: ";

    while (!(cin >> ndKiekis) || ndKiekis <= 0) {
        cout << "Neteisinga ivestis, bandykite dar karta: ";

        cin.clear();
        cin.ignore(80, '\n');
    }

    cin.clear();
    cin.ignore(80, '\n');

    list<Studentas> grupe;

    while (arTesti) {
        Studentas temp;
        pildyti(temp, arTesti, ndKiekis);
        if (!arTesti) break;

        grupe.push_back(temp);
    }

    if (grupe.size() == 0) return;

    cout << setw(20) << left << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis (vid.)" << setw(20) << "Galutinis (med.)" << endl;
    cout << string(80, '-') << endl; 

    grupe.sort();

    for (const auto& i : grupe) cout << i << endl;

    grupe.clear();
}

void generuoti_failus() {
    int ndKiekis;
    cout << "Kiek namu darbu pazymiu norite sugeneruoti kiekvienam studentui? "; cin >> ndKiekis;
    while (!cin || ndKiekis <= 0) {
        cout << "Neteisinga ivestis. Bandykite dar karta: ";

        cin.clear();
        cin.ignore(80, '\n');

        cin >> ndKiekis;
    }

    for (int i = 1000; i <= 10000000; i *= 10) {
        auto pradzia = high_resolution_clock::now();

        generuoti_faila(i, ndKiekis);

        auto pabaiga = high_resolution_clock::now();
        auto skirtumas = duration_cast<milliseconds>(pabaiga - pradzia);   
        cout << "Failo su " << i << " studentu generavimas uztruko " << (skirtumas.count() / 1000.0) << "s" << endl;
    }
}

