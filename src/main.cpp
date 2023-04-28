#include "../libs/lib.h"
#include "../libs/apdorojimas.h"

int main() {
    char ivestiesBudas;
    cout << "Kaip norite vykdyti studentu duomenu ivesti? (r - ivesti ranka, f - skaityti is failo, g - generuoti failus) "; cin >> ivestiesBudas;
    while (ivestiesBudas != 'r' && ivestiesBudas != 'f' && ivestiesBudas != 'g') {
        cout << "Neteisinga ivestis, bandykite dar karta: ";

        cin.ignore(80, '\n');
        cin.clear();

        cin >> ivestiesBudas;
    }

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

    if (ivestiesBudas == 'r') ivesti_ranka();
    else if (ivestiesBudas == 'f') skaityti_faila(dalinimo_budas);
    else generuoti_failus();

    return 0;
}