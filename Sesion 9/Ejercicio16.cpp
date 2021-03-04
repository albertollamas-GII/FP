//Alberto Llamas Gonzalez
#include <iostream>

using namespace std;

int main() {

    const int MAX_NUM_ENTEROS = 10000000;
    int v[MAX_NUM_ENTEROS];
    int topk[MAX_NUM_ENTEROS], numero_k = 0;
    int util_v = 0, dato = 0, util_k=0, maximo = 0, posicion_maximo = 0, swap = 0;

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

    for (int izda = 0; izda < numero_k; izda++){
        maximo=topk[izda];
        posicion_maximo = izda;
        for (int j = izda; j < util_v; j++){
            if (maximo < topk[j]){
                maximo = topk[j];
                posicion_maximo = j;
            }
        }

        swap = topk[izda];
        topk[izda] = topk[posicion_maximo];
        topk[posicion_maximo] = swap;
    }
    
    cout << "\nLos k primeros mayores elementos son: ";

    for (int i = 0; i < numero_k; i++)
        cout << topk[i] << " ";
    
    cout << "\n\n";
}