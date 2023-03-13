# Objektinio programavimo laboratoriniai darbai

VU ISI 1k. 2sem. Objektinio programavimo laboratoriniai darbai.

## Apie programą

Studentų duomenų bazė. Studentų duomenis galima įvesti ranka arba skaityti iš failo `kursiokai.txt`. Pasirinkus įvedimą ranka, iš pradžių nurodomas namų darbų kiekis, kuris buvo skirtas studentams, po to studentų duomenys įvedami tol, kol į vardo eilutę neįrašoma "stop". Namų darbų ir egzamino pažymius galima įvesti pačiam arba pasirinkti atsitiktinį skaičių generavimą (nuo 1 iki 10 balų). Įvedant duomenis ranka, galima anksčiau sustabdyti įvestį įrašant "-1" kaip namų darbų pažymį, tačiau vietoje likusių neįvestų pažymių, bus įrašomi nuliai. Studento galutinis pažymys apskaičiuojamas pagal iš anksto suteiktą formulę
![](https://latex.codecogs.com/svg.image?G%20=%200.4%20*%20\frac{\sum_{i=1}^{n}nd_{i}}{n}%20+%200.6%20*%20egz)

Vietoje vidurkio taip pat galima pasirinkti studento namų darbų pažymių medianą.

## Release v0.4

Ketvirtoji programos versija.

### Kas pasikeitė:

1. Pridėtas pasirinkimas generuoti atsitiktinius sąrašus nuo 1000 iki 10000000 studentų.
2. Pridėtas studentų paskirstymas į du failus. Faile `protingi.txt` išvedamas studentų sąrašas, kurių vidurkis >=5, o faile `vargsai.txt` studentų, kurių vidurkis <5.

### Programos spartos analizė

Visi testavimo atvejai pateikti neturint jokių pradinių duomenų failų, o studentai buvo generuojami su penkiais namų darbų pažymiais ir vienu egzamino balu. Visi matavimų vidurkiai pateikti sekundėmis.

| Studentų kiekis | Failo generavimas | Failo skaitymas | Duomenų apdorojimas | Studentų rūšiavimas | Išvedimas į du failus | Visas programos veikimas |
| --------------- | ----------------- | --------------- | ------------------- | ------------------- | --------------------- | ------------------------ |
| 1 000           | 0.003             | 0.004           | 0.003               | 0.001               | 0.004                 | 0.011                    |
| 10 000          | 0.01              | 0.03            | 0.03                | 0.004               | 0.02                  | 0.085                    |
| 100 000         | 0.09              | 0.1             | 0.14                | 0.055               | 0.17                  | 0.47                     |
| 1 000 000       | 0.85              | 0.8             | 1.3                 | 0.65                | 1.7                   | 4.45                     |
| 10 000 000      | 9.85              | 7.8             | 14.2                | 7.7                 | 16.5                  | 46.2                     |

## Release v0.3

Trečioji programos versija.

### Kas pasikeitė:

1. Projektas paskirstytas į mažesnius failus.
2. Pridėtas klaidų valdymas skaitant duomenų failą.

## Release v0.2

Antroji programos versija.

### Kas pasikeitė:

1. Projekte paliktas tik vienas `main.cpp` failas su `<vector>` realizacija.
2. Pridėtas duomenų skaitymas iš `kursiokai.txt` failo, kurio apdoroti duomenys įrašomi į `apdorota.txt` failą.
3. Pakeistas atsitiktinių skaičių generavimas. Vietoje C kalbos `srand()` naudojama C++ `<random>` biblioteka.
4. Pakeistas studentų įvedimo ranka sustabdymas. Nuo šiol užtenka įrašyti "stop" į vardo eilutę.
5. Pridėtas studentų rikiavimas pagal vardą abėcėlės tvarka prieš spausdinimą/įrašymą į failą.

## Release v0.1

Pirmoji programos versija.

Faile `sprendimas_1.cpp` pateiktas užduoties sprendimas naudojantis C++ standartine biblioteka `<vector>` studentų ir jų namų darbų pažymių laikymui. Faile `sprendimas_2.cpp` pateikta antra užduoties iteracija, kurioje vietoj `<vector>` buvo naudojami paprasti dinaminiai C kalbos masyvai.
