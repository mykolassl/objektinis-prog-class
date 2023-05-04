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

## Release v1.2

Aštuntoji programos versija.

### Kas pasikeitė:

1. Pridėti kopijavimo ir perkėlimo kontruktoriai ir priskyrimo operatoriai.

## Release v1.1

Septintoji programos versija.

### Kas pasikeitė:

1. Vietoje studento struktūros naudojama klasė.
2. Kai kurios bendro naudojimo funkcijos pakeistos į templates.

### Spartos analizė

Visiems bandymams buvo naudojamas sparčiausias (antras) konteinerių dalijimo būdas.

<details>
<summary>Vector</summary>

| Optimizavimas   | Studentų kiekis | Failo skaitymas | Duomenų apdorojimas | Studentų rikiavimas | Studentų atskyrimas į dvi grupes | Išvedimas į du failus | Visas programos veikimas |
| --------------- | --------------- | --------------- | ------------------- | ------------------- | -------------------------------- | --------------------- | ------------------------ |
| Be optimizavimo | 100 000         | 0.084           | 0.26                | 0.406               | 0.04                             | 0.11                  | 0.9                      |
|                 | 1 000 000       | 0.839           | 2.42                | 5.17                | 0.41                             | 1.07                  | 9.9                      |
| -O1             | 100 000         | 0.083           | 0.14                | 0.085               | 0.015                            | 0.098                 | 0.42                     |
|                 | 1 000 000       | 0.825           | 1.298               | 1.17                | 0.159                            | 0.858                 | 4.3                      |
| -O2             | 100 000         | 0.085           | 0.135               | 0.08                | 0.014                            | 0.09                  | 0.4                      |
|                 | 1 000 000       | 0.808           | 1.3                 | 1.067               | 0.144                            | 0.875                 | 4.195                    |
| -O3             | 100 000         | 0.084           | 0.136               | 0.079               | 0.014                            | 0.098                 | 0.411                    |
|                 | 1 000 000       | 0.809           | 1.313               | 1.03                | 0.145                            | 0.85                  | 4.15                     |

| Optimizavimas   | .exe failo dydis (KB) |
| --------------- | --------------------- |
| Be optimizavimo | 762                   |
| -O1             | 417                   |
| -O2             | 396                   |
| -O3             | 405                   |

</details>

<details>
<summary>Deque</summary>

| Optimizavimas   | Studentų kiekis | Failo skaitymas | Duomenų apdorojimas | Studentų rikiavimas | Studentų atskyrimas į dvi grupes | Išvedimas į du failus | Visas programos veikimas |
| --------------- | --------------- | --------------- | ------------------- | ------------------- | -------------------------------- | --------------------- | ------------------------ |
| Be optimizavimo | 100 000         | 0.084           | 0.20                | 0.43                | 0.03                             | 0.11                  | 0.86                     |
|                 | 1 000 000       | 0.81            | 2                   | 5.6                 | 0.36                             | 1.14                  | 9.94                     |
| -O1             | 100 000         | 0.085           | 0.123               | 0.115               | 0.015                            | 0.09                  | 0.43                     |
|                 | 1 000 000       | 0.824           | 1.19                | 1.26                | 0.14                             | 0.87                  | 4.28                     |
| -O2             | 100 000         | 0.083           | 0.122               | 0.092               | 0.014                            | 0.1                   | 0.412                    |
|                 | 1 000 000       | 0.812           | 1.193               | 1.2                 | 0.138                            | 0.87                  | 4.2                      |
| -O3             | 100 000         | 0.086           | 0.121               | 0.1                 | 0.014                            | 0.093                 | 0.42                     |
|                 | 1 000 000       | 0.81            | 1.2                 | 1.14                | 0.14                             | 0.86                  | 4.15                     |

| Optimizavimas   | .exe failo dydis (KB) |
| --------------- | --------------------- |
| Be optimizavimo | 673                   |
| -O1             | 410                   |
| -O2             | 395                   |
| -O3             | 403                   |

</details>

<details>
<summary>List</summary>

| Optimizavimas   | Studentų kiekis | Failo skaitymas | Duomenų apdorojimas | Studentų rikiavimas | Studentų atskyrimas į dvi grupes | Išvedimas į du failus | Visas programos veikimas |
| --------------- | --------------- | --------------- | ------------------- | ------------------- | -------------------------------- | --------------------- | ------------------------ |
| Be optimizavimo | 100 000         | 0.086           | 0.21                | 0.078               | 0.057                            | 0.125                 | 0.55                     |
|                 | 1 000 000       | 0.85            | 2.15                | 1.05                | 0.59                             | 1.16                  | 5.8                      |
| -O1             | 100 000         | 0.08            | 0.128               | 0.03                | 0.037                            | 0.09                  | 0.37                     |
|                 | 1 000 000       | 0.82            | 1.24                | 0.52                | 0.36                             | 0.9                   | 3.87                     |
| -O2             | 100 000         | 0.086           | 0.13                | 0.028               | 0.038                            | 0.094                 | 0.377                    |
|                 | 1 000 000       | 0.813           | 1.292               | 0.516               | 0.365                            | 0.904                 | 3.89                     |
| -O3             | 100 000         | 0.085           | 0.125               | 0.029               | 0.037                            | 0.097                 | 0.373                    |
|                 | 1 000 000       | 0.81            | 1.22                | 0.519               | 0.363                            | 0.9                   | 3.8                      |

| Optimizavimas   | .exe failo dydis (KB) |
| --------------- | --------------------- |
| Be optimizavimo | 601                   |
| -O1             | 365                   |
| -O2             | 363                   |
| -O3             | 359                   |

</details>

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
