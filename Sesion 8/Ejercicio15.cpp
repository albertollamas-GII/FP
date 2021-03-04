#include <iostream>

using namespace std;

int main() {

    const int MAX_NUM_ENTEROS = 100;
    int v[MAX_NUM_ENTEROS];
    int topk[MAX_NUM_ENTEROS], numero_k = 0;
    int util_v = 0, dato = 0, util_k=0;

    cout << "\nIntroduzca una serie de datos enteros positivos: ";
    cin >> dato;

    while (dato >= 0 && util_v < MAX_NUM_ENTEROS){
        v[util_v] = dato;
        util_v++;
        cin >> dato;
    }

    cout << "\nIntroduzca el numero de elementos mayores que quiere sacar de los datos anteriores: ";
    cin >> numero_k;
    
    util_k = util_v;

    for (int i = 0; i < util_v; i++) {
        topk[i] = v[i];
    }

    //Ordenacion por insercion
    int a_desplazar, p;

    for (int izda = 1; izda < util_k; izda++) {
        a_desplazar = topk[izda];

        //si la posicion actual es mayor que la anterior, intercambiamos
        for (p = izda; p > 0 && a_desplazar > topk[p - 1]; p--)
            topk[p] = topk[p - 1];

        topk[p] = a_desplazar;
    }

    cout << "\nLos k primeros mayores elementos son: ";

    for (int i = 0; i < numero_k; i++)
        cout << topk[i] << " ";
    
    cout << "\n\n";
}