#include <iostream>

using namespace std;

int Max2 (int entero1, int entero2) {
    int max = entero2;

    if (entero1 > entero2) 
        max=entero1;

    return max;
}

int Max3 (int entero1, int entero2, int entero3) {

    int max=Max2(entero1, entero2);

    if (entero3 > max)
        max=entero3;
    
    return max;
}


int main() {

    int dato1 = 0, dato2 = 0, dato3 = 0;

    cout << "\nIntroduzca tres enteros para calcular el maximo introducido: ";
    cin >> dato1 >> dato2 >> dato3;

    int maximo = Max3(dato1,dato2,dato3);

    cout << "\nEl maximo es: " << maximo << endl;

}