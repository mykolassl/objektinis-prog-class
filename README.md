# Objektinio programavimo laboratoriniai darbai

VU ISI 1k. 2sem. Objektinio programavimo laboratoriniai darbai.

## Apie programą

Ši programa apdoroja studentų namų darbų bei egzamino pažymius ir išveda jų vardus, pavardes bei galutinius pažymius. Studentų duomenis galima įvesti ranka, skaityti iš jau egzistuojančio failo arba sugeneruoti penkis failus su atsitiktiniais duomenimis.

## Naudojimosi instrukcija

Pirmo naudojimosi karto metu reikia paleisti `build.bat` failą. Baigus diegimą, programa pirmą kartą pasileis automatiškai, norint paleisti programą dar kartą, ją galima rasti aplanke `Debug/Laboratorinis.exe`. Pasileidus programai nurodoma kaip bus įvesti studentų duomenys: įvesti ranka, perskaityti iš failo arba sugeneruoti atsitiktiniai failai.

> ### Įvedimas ranka
>
> Pasirinkus įvedimą ranka, iš pradžių nurodomas namų darbų kiekis, kuris buvo skirtas studentams, po to studentų duomenys įvedami tol, kol į vardo eilutę neįrašoma "stop". Namų darbų ir egzamino pažymius galima įvesti pačiam arba pasirinkti atsitiktinį skaičių generavimą (nuo 1 iki 10 balų). Įvedant duomenis ranka, galima anksčiau sustabdyti įvestį įrašant "-1" kaip namų darbų pažymį, tačiau vietoje likusių neįvestų pažymių, bus įrašomi nuliai.

> ### Skaitymas iš failo
>
> Pasirinkus skaitymą iš failo, iš sąrašo nurodomas failo numeris, kurį norima nuskaityti. Tada pasirenkamas vienas iš dviejų studentų konteinerio dalinimo būdų. Pirmas variantas vienu programos veikimo metu trumpam užima daugiau atminties ir kai kuriais atvejais yra lėtesnis, antras variantas panaudoja mažiau atminties ir yra greitesnis. Atlikus failo apdorojimą, programa išveda du failus `protingi.txt` ir `vargsai.txt`, kuriuose atitinkamai pateikti studentai, kurių galutinis balas pagal vidurkį yra >=5 ir <5.

> ### Failų generavimas
>
> Pasirinkus failų generavimą, nurodomas studentam užduotų namų darbų kiekis. Baigus generavimą, aplanke atsiranda penki failai, kuriuose sugeneruotas studentų skaičius yra nuo 1 000 iki 10 000 000.

Studento galutinis pažymys apskaičiuojamas pagal iš anksto suteiktą formulę
![](https://latex.codecogs.com/svg.image?G%20=%200.4%20*%20\frac{\sum_{i=1}^{n}nd_{i}}{n}%20+%200.6%20*%20egz)

## Release v1.0

Šeštoji programos versija.

### Kas pasikeitė:

1. Pagreitintas rašymas į failą.
2. Pridėtas CMake build failas.
3. Pridėtas studentų konteinerio dalinimo būdo pasirinkimas.

### Spartos analizė

<details>
<summary>Vector</summary>

| Studentų kiekis | Failo skaitymas | Duomenų apdorojimas | Studentų rikiavimas | Studentų atskyrimas į dvi grupes\* | Išvedimas į du failus | Visas programos veikimas\* |
| --------------- | --------------- | ------------------- | ------------------- | ---------------------------------- | --------------------- | -------------------------- |
| 1 000           | 0.004           | 0.003               | 0.0009              | 0.0006 / 0.0006                    | 0.003                 | 0.011 / 0.011              |
| 10 000          | 0.03            | 0.03                | 0.001               | 0.002 / 0.001                      | 0.014                 | 0.081 / 0.08               |
| 100 000         | 0.1             | 0.14                | 0.055               | 0.04 / 0.027                       | 0.11                  | 0.46 / 0.45                |
| 1 000 000       | 0.8             | 1.3                 | 0.58                | 0.4 / 0.26                         | 1.1                   | 4.18 / 3.95                |
| 10 000 000      | 8.5             | 13.6                | 4.5                 | 3.9 / 3.2                          | 9.5                   | 41.2 / 39.3                |

\* Pateikti du dalinimo variantų rezultatai - pirmas / antras.

</details>

<details>
<summary>Deque</summary>

| Studentų kiekis | Failo skaitymas | Duomenų apdorojimas | Studentų rikiavimas | Studentų atskyrimas į dvi grupes\* | Išvedimas į du failus | Visas programos veikimas\* |
| --------------- | --------------- | ------------------- | ------------------- | ---------------------------------- | --------------------- | -------------------------- |
| 1 000           | 0.001           | 0.002               | 0.0006              | 0.0007 / 0.0008                    | 0.002                 | 0.0065 / 0.0064            |
| 10 000          | 0.012           | 0.016               | 0.0025              | 0.004 / 0.002                      | 0.016                 | 0.05 / 0.048               |
| 100 000         | 0.096           | 0.16                | 0.05                | 0.05 / 0.033                       | 0.11                  | 0.47 / 0.45                |
| 1 000 000       | 0.85            | 1.5                 | 0.62                | 0.51 / 0.3                         | 1.1                   | 4.58 / 4.3                 |
| 10 000 000      | 8.3             | 13.15               | 5.8                 | 5.55 / 3.16                        | 9.4                   | 42.3 / 39.81               |

\* Pateikti du dalinimo variantų rezultatai - pirmas / antras.

</details>

<details>
<summary>List</summary>

| Studentų kiekis | Failo skaitymas | Duomenų apdorojimas | Studentų rikiavimas | Studentų atskyrimas į dvi grupes\* | Išvedimas į du failus | Visas programos veikimas\* |
| --------------- | --------------- | ------------------- | ------------------- | ---------------------------------- | --------------------- | -------------------------- |
| 1 000           | 0.0015          | 0.002               | 0.0007              | 0.0008 / 0.0007                    | 0.003                 | 0.007 / 0.007              |
| 10 000          | 0.014           | 0.019               | 0.003               | 0.005 / 0.004                      | 0.015                 | 0.056 / 0.055              |
| 100 000         | 0.1             | 0.15                | 0.045               | 0.08 / 0.056                       | 0.11                  | 0.485 / 0.46               |
| 1 000 000       | 0.8             | 1.43                | 0.59                | 0.72 / 0.47                        | 0.92                  | 4.5 / 4.2                  |
| 10 000 000      | 8.7             | 14.3                | 9.2                 | 7.7 / 4.61                         | 10.1                  | 50.2 / 46.9                |

\* Pateikti du dalinimo variantų rezultatai - pirmas / antras.

</details>

## Release v0.5

Penktoji programos versija.

### Kas pasikeitė:

1. Palengvintas norimo apdoroti failo pasirinkimas.
2. Pridėtos dvi naujos programos realizacijos naudojant `list` ir `deque` konteinerius, kurios pateiktos atitinkamose `v0.5-list` ir `v0.5-deque` šakose.

### Programos spartos analizė

<details>
<summary>Vector</summary>

| Studentų kiekis | Failo skaitymas | Duomenų apdorojimas | Studentų rikiavimas | Studentų atskyrimas į dvi grupes | Išvedimas į du failus | Visas programos veikimas |
| --------------- | --------------- | ------------------- | ------------------- | -------------------------------- | --------------------- | ------------------------ |
| 1 000           | 0.004           | 0.003               | 0.0009              | 0.0006                           | 0.004                 | 0.011                    |
| 10 000          | 0.03            | 0.03                | 0.001               | 0.002                            | 0.02                  | 0.085                    |
| 100 000         | 0.1             | 0.14                | 0.055               | 0.061                            | 0.17                  | 0.54                     |
| 1 000 000       | 0.8             | 1.3                 | 0.58                | 0.48                             | 1.7                   | 5.1                      |
| 10 000 000      | 8.5             | 15.3                | 9.1                 | 4.84                             | 17.4                  | 56.4                     |

</details>

<details>
<summary>Deque</summary>

| Studentų kiekis | Failo skaitymas | Duomenų apdorojimas | Studentų rikiavimas | Studentų atskyrimas į dvi grupes | Išvedimas į du failus | Visas programos veikimas |
| --------------- | --------------- | ------------------- | ------------------- | -------------------------------- | --------------------- | ------------------------ |
| 1 000           | 0.001           | 0.002               | 0.0006              | 0.0007                           | 0.0045                | 0.0075                   |
| 10 000          | 0.012           | 0.016               | 0.0025              | 0.004                            | 0.024                 | 0.06                     |
| 100 000         | 0.096           | 0.16                | 0.05                | 0.068                            | 0.18                  | 0.55                     |
| 1 000 000       | 0.85            | 1.5                 | 0.62                | 0.51                             | 1.63                  | 5.1                      |
| 10 000 000      | 8.3             | 13.94               | 8.9                 | 4.85                             | 17.8                  | 53.8                     |

</details>

<details>
<summary>List</summary>

| Studentų kiekis | Failo skaitymas | Duomenų apdorojimas | Studentų rikiavimas | Studentų atskyrimas į dvi grupes | Išvedimas į du failus | Visas programos veikimas |
| --------------- | --------------- | ------------------- | ------------------- | -------------------------------- | --------------------- | ------------------------ |
| 1 000           | 0.0015          | 0.002               | 0.0007              | 0.0008                           | 0.003                 | 0.007                    |
| 10 000          | 0.014           | 0.019               | 0.003               | 0.005                            | 0.03                  | 0.07                     |
| 100 000         | 0.1             | 0.15                | 0.045               | 0.06                             | 0.18                  | 0.52                     |
| 1 000 000       | 0.86            | 1.43                | 0.65                | 0.5                              | 1.7                   | 5.2                      |
| 10 000 000      | 8.7             | 15                  | 9.2                 | 4.9                              | 18.5                  | 57.6                     |

</details>

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
