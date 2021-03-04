#include <iostream>

using namespace std;

int main () {

    //Ejercicio 3.10
    const int TERMINADOR_DECOD = 0;

    float frecuencia;
    double dato;
    int frecuencia_int;
    bool error_inesperado = false;

    cout << "\nIntroduzca en formato <frecuencia> <dato> para decodificar mediante la forma RLE. " << endl;
    cin >> frecuencia;

    while (frecuencia != TERMINADOR_DECOD){
        frecuencia_int = frecuencia;
        if (frecuencia > 0 && frecuencia == frecuencia_int) {
            cin >> dato;

            for (int i = 1; i <=frecuencia; i++)
                cout << dato << " ";
            
            cin >> frecuencia;
            error_inesperado= false;
        } else if (frecuencia!=frecuencia_int) {
            cout << "\nError inesperado, frecuencia no entera. ";
            frecuencia = TERMINADOR_DECOD;
            error_inesperado = true;
        } else {
            cout << "\nError inesperado, valor de frecuencia sin sentido. " ; 
            frecuencia = TERMINADOR_DECOD;
            error_inesperado = true;
        }
    }

    if (frecuencia == 0 && !error_inesperado)
        cout << "-300";

    cout << "\n\n";
}