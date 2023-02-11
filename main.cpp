#include "lib.h"

struct Studentas {
    string vardas;
    string pavarde;
    
    int egzPazymys;
    vector<int> ndPazymiai;
};

int main () {
    int studKiekis;
    cin >> studKiekis;

    for (int i = 0; i < studKiekis; i++) {
        int ndKiekis;
        Studentas studentas;
        
        cout << "Iveskite studento varda bei pavarde ";
        cin >> studentas.vardas >> studentas.pavarde;

        cout << "Iveskite namu darbu kieki ";
        cin >> ndKiekis;
        studentas.ndPazymiai.reserve(ndKiekis);

        for (int j = 1; j <= ndKiekis; j++) {
            int pazymys = 0;

            do {
                cout << "Iveskite " << j << "-aji studento namu darbu pazymi ";
                cin >> pazymys;
            } while (pazymys <= 0 || pazymys > 10); 

            studentas.ndPazymiai.push_back(pazymys);
        }

    }

    return 0;    
}
