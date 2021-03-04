//Alberto Llamas Gonzalez

#include <iostream>
using namespace std;

int main() {
    const char TERMINADOR = '#';
    const int MAX_NUM_CARACT = 200;
    char grande[MAX_NUM_CARACT],
        peque[MAX_NUM_CARACT];
    char car;
    int util_grande, util_peque;
    int num_leidos;
    bool encontrado = false;

    cout << "Búsqueda -débil- de un vector de carteres dentro de otro\n"
         << "Introduzca los cartereses del vector grande, con terminador "
         << TERMINADOR << "\n"
         << "A continuación introduzca  los caracterees del vector pequeño,"
         << " usando el mismo terminador.\n\n";

    // Lectura

    car = cin.get();
    num_leidos = 0;

    while (car != TERMINADOR && num_leidos < MAX_NUM_CARACT) {
        grande[num_leidos] = car;
        car = cin.get();
        num_leidos++;
    }

    util_grande = num_leidos;

    car = cin.get();
    num_leidos = 0;

    while (car != TERMINADOR && num_leidos < MAX_NUM_CARACT) {
        peque[num_leidos] = car;
        car = cin.get();
        num_leidos++;
    }

    util_peque = num_leidos;

    ///////////////////////////////////////////////////////////
    // Incluya aquí el código para realizar la búsqueda
    ///////////////////////////////////////////////////////////
    int contador = 0;

    for (int i = 0; i < util_grande; i++){
        if (grande [i] == peque[contador])
            contador++;
    }

    if (contador == util_peque)
        encontrado = true;

    cout << "\n";

    if (encontrado)
        cout << "\nEl vector pequeño está dentro del grande";
    else
        cout << "\nEl vector pequeño NO está dentro del grande";
    
    cout << "\n\n";

}
