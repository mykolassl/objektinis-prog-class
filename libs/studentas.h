#pragma once

#include <string>
#include <vector>
#include "pagalbines_funk.h"

// bool palyginti_vardus(const Studentas& , const Studentas& );
// bool palyginti_vidurkius(const Studentas& , const Studentas& );

class Studentas {
private:
    std::string m_Vardas, m_Pavarde;
    double m_Galutinis_vid, m_Galutinis_med;
    int m_EgzPazymys;
    std::vector<int> m_NdPazymiai;

public:
    Studentas()
        : m_Vardas(""), m_Pavarde(""), m_Galutinis_vid(0), m_Galutinis_med(0), m_EgzPazymys(0) {}

    void vardas(std::string vardas) { m_Vardas = vardas; }
    std::string vardas() const { return m_Vardas; }

    void pavarde(std::string pavarde) { m_Pavarde = pavarde; }
    std::string pavarde() const { return m_Pavarde; } 

    void pazymiai(std::vector<int>& nd) { 
        m_EgzPazymys = nd.back();
        nd.pop_back();
        m_NdPazymiai = nd;
        m_Galutinis_vid = 0.6 * apskaiciuoti_vidurki(m_NdPazymiai) + 0.4 * m_EgzPazymys;      
        m_Galutinis_med = 0.6 * apskaiciuoti_mediana(m_NdPazymiai) + 0.4 * m_EgzPazymys;
    }
    void pazymiai(std::vector<int>& nd, int egzaminas) { 
        m_EgzPazymys = egzaminas;
        m_NdPazymiai = nd;
        m_Galutinis_vid = 0.6 * apskaiciuoti_vidurki(m_NdPazymiai) + 0.4 * m_EgzPazymys;      
        m_Galutinis_med = 0.6 * apskaiciuoti_mediana(m_NdPazymiai) + 0.4 * m_EgzPazymys;
    }
    std::vector<int> pazymiai() const { return m_NdPazymiai; }

    double galutinis_vid() const { return m_Galutinis_vid; }
    double galutinis_med() const { return m_Galutinis_med; }

    friend bool operator>(const Studentas& A, const Studentas& B) {
        return A.m_Galutinis_vid > B.m_Galutinis_vid;
    }

    friend bool operator<(const Studentas& A, const Studentas& B) {
        return A.m_Galutinis_vid < B.m_Galutinis_vid;
    }
};



