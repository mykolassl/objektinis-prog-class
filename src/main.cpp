#include "../libs/lib.h"
#include "../libs/apdorojimas.h"

int main() {
    char ivestiesBudas;
    cout << "Ar studentus norite vesti ranka, ar skaityti is failo? (r - ranka, f - is failo) "; cin >> ivestiesBudas;
    while (ivestiesBudas != 'r' && ivestiesBudas != 'f') {
        cout << "Neteisinga ivestis, bandykite dar karta: ";

        cin.ignore(80, '\n');
        cin.clear();

        cin >> ivestiesBudas;
    }

    if (ivestiesBudas == 'r') ivesti_ranka();
    else skaityti_faila();

    return 0;
}