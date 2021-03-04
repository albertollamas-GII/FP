#include <iostream>

using namespace std;

int main () {

    //Ejercicio 3.9 : Codificacion RLE
    const double TERMINADOR_COD = -273.15;

    double actual, anterior, terminador = 0;
    int iguales_hasta_ahora = 1;

    cout << "\nIntroduzca numeros reales para aplicar la codificación RLE. " << endl;
    cin >> actual;

    while (actual >= TERMINADOR_COD){

        anterior = actual;
        cin >> actual;

        if (anterior == actual)
            iguales_hasta_ahora++;
        else {
            cout << iguales_hasta_ahora << " " << anterior << " ";
            iguales_hasta_ahora = 1;
        }
    }

    if (iguales_hasta_ahora == 1)
        cout << "0";

    cout << "\n\n";


}