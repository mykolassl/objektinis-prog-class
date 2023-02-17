# Objektinio programavimo laboratoriniai darbai

VU ISI 1k. 2sem. Objektinio programavimo laboratoriniai darbai.

## Apie programą

Studentų duomenų bazė. Iš pradžių nurodomas namų darbų kiekis, kuris buvo skirtas studentams, po to studentų duomenys įvedami tol, kol į vardo ir pavardės eilutę neįrašoma "stop stop". Namų darbų ir egzamino pažymius galima įvesti pačiam arba pasirinkti atsitiktinį skaičių generavimą (nuo 1 iki 10 balų). Įvedant duomenis ranka, galima anksčiau sustabdyti įvestį įrašant "-1" kaip namų darbų pažymį, tačiau vietoje likusių neįvestų pažymių, bus įrašomi nuliai. Studento galutinis pažymys apskaičiuojamas pagal iš anksto suteiktą formulę
![](https://latex.codecogs.com/svg.image?\bg{white}G=0.4%20*%20\sum_{i=1}^{a}nd_{i}%20+%200.6%20*%20egz)

Vietoje vidurkio taip pat galima pasirinkti studento namų darbų pažymių medianą.

## Release v0.1

Pirmoji programos versija.

Faile `sprendimas_1.cpp` pateiktas užduoties sprendimas naudojantis C++ standartine biblioteka `<vector>` studentų ir jų namų darbų pažymių laikymui. Faile `sprendimas_2.cpp` pateikta antra užduoties iteracija, kurioje vietoj `<vector>` buvo naudojami paprasti dinaminiai C kalbos masyvai.
