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

    char konteinerioTipas;
    cout << "Koki konteinerio studentu laikymui norite panaudoti? (v - vector, d - deque, l - list) "; cin >> konteinerioTipas;
    while (konteinerioTipas != 'v' && konteinerioTipas != 'd' && konteinerioTipas != 'l') {
        cout << "Neteisinga ivestis, bandykite dar karta: ";

        cin.ignore(80, '\n');
        cin.clear();

        cin >> konteinerioTipas;
    }

    // if (konteinerioTipas == 'v') {
        if (ivestiesBudas == 'r') ivesti_ranka();
        else if (ivestiesBudas == 'f') skaityti_faila();
        else generuoti_failus();
    // }


    return 0;
}