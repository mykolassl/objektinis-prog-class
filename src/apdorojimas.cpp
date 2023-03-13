#include "../libs/lib.h"
#include "../libs/studentas.h"
#include "../libs/pagalbines_funk.h"
#include "../libs/apdorojimas.h"

void pildyti(Studentas& stud, bool& arTesti, int ndKiekis) {
    // ************** Vardas ir pavarde **************
    cout << "Iveskite studento varda: "; cin >> stud.vardas;

    cin.ignore(80, '\n');
    cin.clear();

    if (stud.vardas == "stop") {
        arTesti = false;
        stud.vardas = "";
        cout << "Studentu duomenu ivestis stabdoma" << endl << endl;
        return;
    }

    cout << "Iveskite studento pavarde: "; cin >> stud.pavarde;

    cin.ignore(80, '\n');
    cin.clear();

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
        generuoti_pazymius(stud);
        stud.galutinis_vid = 0.4 * apskaiciuoti_vidurki(stud) + 0.6 * stud.egzPazymys;
        stud.galutinis_med = 0.4 * apskaiciuoti_mediana(stud) + 0.6 * stud.egzPazymys;
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

    cin.clear();
    cin.ignore(80, '\n');

    stud.egzPazymys = egzPazymys;
    stud.galutinis_vid = 0.4 * apskaiciuoti_vidurki(stud) + 0.6 * stud.egzPazymys;
    stud.galutinis_med = 0.4 * apskaiciuoti_mediana(stud) + 0.6 * stud.egzPazymys;

    cout << "Studento duomenys sekmingai ivesti." << endl << endl;
}

void spausdinti(const Studentas stud) {
    cout << setw(20) << stud.vardas << setw(20) << stud.pavarde 
    << setw(20) << fixed << setprecision(2) << stud.galutinis_vid << setw(20) << stud.galutinis_med << endl;
}

void skaityti_faila() {
    stringstream ssIn;
    string failoPav;

    time_point<high_resolution_clock> pradzia, pabaiga;
    milliseconds visasLaikas = milliseconds::zero(), skirtumas;

    while (true) {
        try {
            cout << "Iveskite pilna failo pavadinima is zemiau pateikto saraso:" << endl;
            system("dir /b *.txt");

            cin >> failoPav;

            pradzia = high_resolution_clock::now();

            ifstream fin;
            fin.exceptions(ifstream::failbit | ifstream::badbit);
            fin.open(failoPav);

            ssIn << fin.rdbuf();
            
            fin.close();

            pabaiga = high_resolution_clock::now();
            skirtumas = duration_cast<milliseconds>(pabaiga - pradzia);
            visasLaikas += skirtumas;
            cout << "Failo skaitymas uztruko " << skirtumas.count() / 1000.0 << "s" << endl;

            break;
        } catch (...) {
            cout << "Failas pavadinimu " << failoPav << " nerastas. Bandykite dar Karta." << endl << endl;
        }
    }

    // Pazymiu kiekio, iskaitant egzamina, nustatymas.
    string eilute;
    stringstream ssTemp;
    int pazymiuKiekis = 0;

    pradzia = high_resolution_clock::now();

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

    Studentas stud;
    vector<Studentas> grupe;
    int pazymys;
    stud.ndPazymiai.reserve(pazymiuKiekis);

    while (!ssIn.eof()) {
        ssIn >> stud.vardas >> stud.pavarde;

        for (int i = 0; i < pazymiuKiekis; i++) {
            ssIn >> pazymys;

            if (!ssIn || pazymys < 0 || pazymys > 10) {
                cout << "Klaida! Studento " << stud.vardas << " " << stud.pavarde << " duomenys ivesti neteisingai." << endl;
                ssIn.clear();
                return;
            }

            stud.ndPazymiai.push_back(pazymys);
        }

        // Paskutinis pazymys visada egzamino
        stud.egzPazymys = stud.ndPazymiai.back();
        stud.ndPazymiai.pop_back();
        stud.galutinis_vid = 0.4 * apskaiciuoti_vidurki(stud) + 0.6 * stud.egzPazymys;
        stud.galutinis_med = 0.4 * apskaiciuoti_mediana(stud) + 0.6 * stud.egzPazymys;

        ssIn.ignore(INT_MAX, '\n');
        grupe.push_back(stud);

        stud.ndPazymiai.clear();
    }

    pabaiga = high_resolution_clock::now();
    skirtumas = duration_cast<milliseconds>(pabaiga - pradzia);
    visasLaikas += skirtumas;
    cout << "Failo duomenu apdorojimas uztruko " << skirtumas.count() / 1000.0 << "s" << endl;

    pradzia = high_resolution_clock::now();

    sort(par, grupe.begin(), grupe.end(), palyginti_vidurkius);
    auto splitItr = find_if(grupe.begin(), grupe.end(), surasti_maziausia);

    vector<Studentas> protingi(splitItr, grupe.end());
    grupe.resize(grupe.size() - protingi.size());
    grupe.shrink_to_fit();
    
    pabaiga = high_resolution_clock::now();
    skirtumas = duration_cast<milliseconds>(pabaiga - pradzia);
    visasLaikas += skirtumas;
    cout << "Studentu rusiavimas i vargsus ir protingus uztruko " << skirtumas.count() / 1000.0 << "s" << endl;

    pradzia = high_resolution_clock::now();

    isvesti_faila(grupe, "vargsai");
    isvesti_faila(protingi, "protingi");

    pabaiga = high_resolution_clock::now();
    skirtumas = duration_cast<milliseconds>(pabaiga - pradzia);
    visasLaikas += skirtumas;
    cout << "Vargsu ir protingu isvedimas i du failus uztruko " << skirtumas.count() / 1000.0 << "s" << endl;
    
    cout << "Is viso failo apdorojimas uztruko " << visasLaikas.count() / 1000.0 << " sekundes." << endl;

    grupe.clear();
    protingi.clear();
}

void isvesti_faila(vector<Studentas>& grupe, string failoPav) {
    stringstream ssOut;
    ssOut << setw(20) << left << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis (vid.)" << setw(20) << "Galutinis (med.)" << endl;
    ssOut << string(80, '-') << endl; 

    for (auto& i : grupe) {
        ssOut << left << setw(20) << i.vardas << setw(20) << i.pavarde 
        << setw(20) << fixed << setprecision(2) << i.galutinis_vid << setw(20) << i.galutinis_med << endl;
    }

    ofstream fout(failoPav + ".txt");
    fout << ssOut.rdbuf();
    fout.close();
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

    vector<Studentas> grupe;

    while (arTesti) {
        Studentas temp;
        pildyti(temp, arTesti, ndKiekis);
        if (!arTesti) break;

        grupe.push_back(temp);
    }

    if (grupe.size() == 0) return;

    cout << setw(20) << left << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis (vid.)" << setw(20) << "Galutinis (med.)" << endl;
    cout << string(80, '-') << endl; 

    sort(grupe.begin(), grupe.end(), palyginti_vardus);

    for (const auto& i : grupe) spausdinti(i);

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