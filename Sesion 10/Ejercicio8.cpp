//Alberto Llamas Gonzalez

#include <iostream>

using namespace std;

int LeeIntMayorIgual (int entero){
    int numero = 0;
    cout << "\nIntroduzca el valor maximo del intervalo: (debe ser mayor que el minimo introducido) ";
    do {
        cin >> numero;
    } while (numero < entero);

    return numero;
}

int LeeIntRango(int min, int max, string mensaje){
    int a_leer;

    cout << "\nIntervalo [ " << min << " , " << max << " ]";
    do{
        cout << mensaje;
        cin >> a_leer;
    } while (min > a_leer || max < a_leer);

    return a_leer;
}
int main(){

    int min = 0;

    cout << "\nIntroduzca el valor minimo del intervalo: ";
    cin >> min;

    int max = LeeIntMayorIgual(min);

    int n = LeeIntRango(min, max, "\nIntroduzca un valor en dicho intervalo: ");

    cout << "\nEl valor introducido es " << n << " que se encuentra en el intervalo [ " << min << " , " << max << " ]";
    cout << endl;
}