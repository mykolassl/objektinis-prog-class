#include "../libs/lib.h"
#include "../libs/studentas.h"
#include "../libs/pagalbines_funk.h"

void dalinimas_1(vector<Studentas>& grupe, vector<Studentas>& vargsai, vector<Studentas>& protingi) {
    auto splitItr = find_if(grupe.begin(), grupe.end(), [](Studentas& stud) {return stud.galutinis_vid() >= 5;});
    vargsai.assign(grupe.begin(), splitItr);
    protingi.assign(splitItr, grupe.end());
    grupe.clear();
}

void dalinimas_2(vector<Studentas>& grupe, vector<Studentas>& protingi) {
    auto splitItr = find_if(grupe.begin(), grupe.end(), [](Studentas& stud) {return stud.galutinis_vid() >= 5;});
    protingi.assign(splitItr, grupe.end());

    grupe.resize(grupe.size() - protingi.size());
    grupe.shrink_to_fit();
}

void isvesti_faila(vector<Studentas>& grupe, string failoPav) {
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

void pildyti(Studentas& stud, bool& arTesti, int ndKiekis) {
    // ************** Vardas ir pavarde **************
    vector<int> pazymiai;
    string vardas, pavarde;
    int egzPazymys;
    cout << "Iveskite studento varda: "; cin >> vardas;

    cin.ignore(80, '\n');
    cin.clear();

    if (stud.vardas() == "stop") {
        arTesti = false;
        stud.vardas("");
        cout << "Studentu duomenu ivestis stabdoma" << endl << endl;
        return;
    }

    cout << "Iveskite studento pavarde: "; cin >> pavarde;

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

    // if (arGeneruoti == 't') {
    //     generuoti_pazymius(stud);
    //     stud.galutinis_vid = 0.4 * apskaiciuoti_vidurki(stud) + 0.6 * stud.egzPazymys;
    //     stud.galutinis_med = 0.4 * apskaiciuoti_mediana(stud) + 0.6 * stud.egzPazymys;
    //     cout << "Studento namu darbu bei egzamino rezultatai sekmingai sugeneruoti." << endl << endl;
    //     return;
    // } 

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

    // stud.egzPazymys = egzPazymys;
    // stud.galutinis_vid = 0.4 * apskaiciuoti_vidurki(stud) + 0.6 * stud.egzPazymys;
    // stud.galutinis_med = 0.4 * apskaiciuoti_mediana(stud) + 0.6 * stud.egzPazymys;

    cout << "Studento duomenys sekmingai ivesti." << endl << endl;
}

void spausdinti(const Studentas stud) {
    cout << setw(20) << stud.vardas() << setw(20) << stud.pavarde() 
    << setw(20) << fixed << setprecision(2) << stud.galutinis_vid() << setw(20) << stud.galutinis_med() << endl;
}

void skaityti_faila() {
    stringstream ssIn;
   
    time_point<high_resolution_clock> pradzia, pabaiga;
    milliseconds visasLaikas = milliseconds::zero(), skirtumas;

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

            pradzia = high_resolution_clock::now();

            ifstream fin;
            fin.exceptions(ifstream::failbit | ifstream::badbit);
            fin.open(failuSarasas.at(failoIndeksas - 1));

            ssIn << fin.rdbuf();
            
            fin.close();

            pabaiga = high_resolution_clock::now();
            skirtumas = duration_cast<milliseconds>(pabaiga - pradzia);
            visasLaikas += skirtumas;
            cout << "Failo skaitymas uztruko " << skirtumas.count() / 1000.0 << "s" << endl;

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
    string vardas, pavarde;
    vector<int> pazymiai;
    int egzaminas, pazymys;

    while (!ssIn.eof()) {
        ssIn >> vardas >> pavarde;
        stud.pavarde(pavarde);
        stud.vardas(vardas);

        for (int i = 0; i < pazymiuKiekis; i++) {
            ssIn >> pazymys;

            if (!ssIn || pazymys < 0 || pazymys > 10) {
                cout << "Klaida! Studento " << vardas << " " << pavarde << " duomenys ivesti neteisingai." << endl;
                ssIn.clear();
                return;
            }

            pazymiai.push_back(pazymys);
        }

        // Paskutinis pazymys visada egzamino
        stud.pazymiai(pazymiai);

        // stud.egzPazymys = stud.ndPazymiai.back();
        // stud.ndPazymiai.pop_back();
        // stud.galutinis_vid = 0.4 * apskaiciuoti_vidurki(stud) + 0.6 * stud.egzPazymys;
        // stud.galutinis_med = 0.4 * apskaiciuoti_mediana(stud) + 0.6 * stud.egzPazymys;

        ssIn.ignore(INT_MAX, '\n');
        grupe.push_back(stud);

        pazymiai.clear();
    }

    pabaiga = high_resolution_clock::now();
    skirtumas = duration_cast<milliseconds>(pabaiga - pradzia);
    visasLaikas += skirtumas;
    cout << "Failo duomenu apdorojimas uztruko " << skirtumas.count() / 1000.0 << "s" << endl;

    pradzia = high_resolution_clock::now();

    sort(grupe.begin(), grupe.end());
    
    pabaiga = high_resolution_clock::now();
    skirtumas = duration_cast<milliseconds>(pabaiga - pradzia);
    visasLaikas += skirtumas;
    cout << "Studentu rikiavimas uztruko " << skirtumas.count() / 1000.0 << "s" << endl;

    pradzia = high_resolution_clock::now();

    vector<Studentas> protingi, vargsai;

    if (dalinimo_budas == 1) dalinimas_1(grupe, vargsai, protingi);
    else dalinimas_2(grupe, protingi);

    pabaiga = high_resolution_clock::now();
    skirtumas = duration_cast<milliseconds>(pabaiga - pradzia);
    visasLaikas += skirtumas;
    cout << "Studentu atskyrimas i vargsus ir protingus uztruko " << skirtumas.count() / 1000.0 << "s" << endl;

    pradzia = high_resolution_clock::now();

    isvesti_faila(dalinimo_budas == 1 ? vargsai : grupe, "vargsai");
    isvesti_faila(protingi, "protingi");

    pabaiga = high_resolution_clock::now();
    skirtumas = duration_cast<milliseconds>(pabaiga - pradzia);
    visasLaikas += skirtumas;
    cout << "Vargsu ir protingu isvedimas i du failus uztruko " << skirtumas.count() / 1000.0 << "s" << endl;
    
    cout << "Is viso failo apdorojimas uztruko " << visasLaikas.count() / 1000.0 << " sekundes." << endl;

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

    sort(grupe.begin(), grupe.end());

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

