#include "../libs/lib.h"
#include "../libs/studentas.h"
#include "../libs/pagalbines_funk.h"

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
        generuoti(stud);
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
    ifstream fin("kursiokai.txt");

    if (!fin) {
        cout << "Failas pavadinimu kursiokai.txt nerastas." << endl;
        return;
    }

    stringstream ssIn;
    ssIn << fin.rdbuf();
    fin.close();

    // Pazymiu kiekio, iskaitant egzamina, nustatymas.
    string eilute;
    stringstream ssTemp;
    int pazymiuKiekis = 0;

    getline(ssIn, eilute);
    eilute.erase(0, 52);
    ssTemp << eilute;

    while (!ssTemp.eof()) {
        string v;
        ssTemp >> v;

        if (v.empty()) continue;

        pazymiuKiekis++;
    }

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

    sort(grupe.begin(), grupe.end(), palyginti_studentus);
    
    stringstream ssOut;

    ssOut << setw(20) << left << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis (vid.)" << setw(20) << "Galutinis (med.)" << endl;
    ssOut << string(80, '-') << endl; 

    for (auto& i : grupe) {
        ssOut << left << setw(20) << i.vardas << setw(20) << i.pavarde 
        << setw(20) << fixed << setprecision(2) << i.galutinis_vid << setw(20) << i.galutinis_med << endl;
    }

    grupe.clear();

    ofstream fout("apdorota.txt");
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

    sort(grupe.begin(), grupe.end(), palyginti_studentus);

    for (const auto& i : grupe) spausdinti(i);

    grupe.clear();
}