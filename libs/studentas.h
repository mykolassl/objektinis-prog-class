#pragma once

#include <string>
#include <vector>
#include "pagalbines_funk.h"

class Studentas {
private:
    std::string m_Vardas, m_Pavarde;
    double m_Galutinis_vid, m_Galutinis_med;
    int m_EgzPazymys, m_Pazymiu_kiekis;
    std::vector<int> m_Nd_pazymiai;

public:
    Studentas()
        : m_Vardas(""), m_Pavarde(""), m_Galutinis_vid(0), m_Galutinis_med(0), m_EgzPazymys(0) {}

    Studentas(int pazymiuKiekis)
        : m_Vardas(""), m_Pavarde(""), m_Galutinis_vid(0), m_Galutinis_med(0), m_EgzPazymys(0), m_Pazymiu_kiekis(pazymiuKiekis) {}

    void vardas(std::string vardas) { m_Vardas = vardas; }
    std::string vardas() const { return m_Vardas; }

    void pavarde(std::string pavarde) { m_Pavarde = pavarde; }
    std::string pavarde() const { return m_Pavarde; } 

    void pazymiai(std::vector<int>& nd) { 
        m_EgzPazymys = nd.back();
        nd.pop_back();
        m_Nd_pazymiai = nd;
        m_Galutinis_vid = 0.4 * apskaiciuoti_vidurki(m_Nd_pazymiai) + 0.6 * m_EgzPazymys;      
        m_Galutinis_med = 0.4 * apskaiciuoti_mediana(m_Nd_pazymiai) + 0.6 * m_EgzPazymys;
    }
    void pazymiai(std::vector<int>& nd, int egzaminas) { 
        m_EgzPazymys = egzaminas;
        m_Nd_pazymiai = nd;
        m_Galutinis_vid = 0.4 * apskaiciuoti_vidurki(m_Nd_pazymiai) + 0.6 * m_EgzPazymys;      
        m_Galutinis_med = 0.4 * apskaiciuoti_mediana(m_Nd_pazymiai) + 0.6 * m_EgzPazymys;
    }
    std::vector<int> pazymiai() const { return m_Nd_pazymiai; }

    double galutinis_vid() const { return m_Galutinis_vid; }
    double galutinis_med() const { return m_Galutinis_med; }

    friend bool operator>(const Studentas& A, const Studentas& B) {
        return A.m_Galutinis_vid > B.m_Galutinis_vid;
    }

    friend bool operator<(const Studentas& A, const Studentas& B) {
        return A.m_Galutinis_vid < B.m_Galutinis_vid;
    }

    friend void operator>>(std::istream& in, Studentas& s) {
        int pazymys;
        in >> s.m_Vardas >> s.m_Pavarde;
        s.m_Nd_pazymiai.clear();

        for (int i = 0; i < s.m_Pazymiu_kiekis; i++) {
            in >> pazymys;

            if (!in || pazymys < 0 || pazymys > 10) {
                cout << "Klaida! Studento " << s.m_Vardas<< " " << s.m_Pavarde << " duomenys ivesti neteisingai." << endl;
                in.clear();
                in.ignore(INT_MAX, '\n');
            }

            s.m_Nd_pazymiai.push_back(pazymys);
        }

        s.m_EgzPazymys = s.m_Nd_pazymiai.back();
        s.m_Nd_pazymiai.pop_back();
        s.m_Galutinis_vid = 0.4 * apskaiciuoti_vidurki(s.m_Nd_pazymiai) + 0.6 * s.m_EgzPazymys;
        s.m_Galutinis_med = 0.4 * apskaiciuoti_mediana(s.m_Nd_pazymiai) + 0.6 * s.m_EgzPazymys;
    }

    friend std::ostream& operator<<(std::ostream& out, const Studentas& s) {
        out << setw(20) << s.m_Vardas << setw(20) << s.m_Pavarde 
            << setw(20) << fixed << setprecision(2) << s.m_Galutinis_vid << setw(20) << s.m_Galutinis_med;
        return out;
    }
};



