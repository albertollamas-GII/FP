#include <iostream>

using namespace std;

int main(){

    const int MAX_FILAS_COLUMNAS = 100;
    int ntecnicos = 0, npedidos = 0, coste_total = 0;
    int tarifas[MAX_FILAS_COLUMNAS][MAX_FILAS_COLUMNAS];
    bool asignaciones[MAX_FILAS_COLUMNAS][MAX_FILAS_COLUMNAS] = {false};

    cin >> ntecnicos;
    npedidos = ntecnicos;

    for (int i = 0; i < ntecnicos; i++)
        for(int j = 0; j < npedidos; j++)
            cin >> tarifas[i][j];

    for (int i = 0; i < ntecnicos; i++){
        int min = 100;
        int pedido_ocupado = -1;
        for (int j = 0; j < npedidos; j++){
            if (min >= tarifas[i][j]){
                bool libre = true;
                for (int k = 0; k < npedidos && libre; k++){
                    if (asignaciones[k][j] != false)
                        libre = false;
                }

                if (libre){
                    pedido_ocupado = j;
                    min = tarifas[i][j]; 
                }
            }
        }

        asignaciones[i][pedido_ocupado] = true;
    }

    for (int i = 0; i < ntecnicos; i++) {
        for (int j = 0; j < npedidos; j++) {
            if (asignaciones[i][j]) {
                coste_total += tarifas[i][j];
                cout << "\nTecnico " << i << " -> Pedido " << j;
            }
        }
    }

    cout << "\nCoste Total: " << coste_total << endl;
}