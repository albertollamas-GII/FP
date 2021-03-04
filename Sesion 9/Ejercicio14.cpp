//Alberto Llamas Gonzalez

#include <iostream>
using namespace std;

int main() {
    const char TERMINADOR = '#';
    const int MAX_NUM_CARACT = 3e6; // Compile con la opción -Wl,--stack,21000000
    char v[MAX_NUM_CARACT],
        nuevo[MAX_NUM_CARACT];
    char a_borrar;
    char car;
    int i, util_v, util_nuevo, num_ocurrencias=0;

    cout << "Sustituye caracter por vector\n"
         << "Introduzca los caracteres del vector, con terminador "
         << TERMINADOR << "\n"
         << "A continuación introduzca el carácter a sustituir y los caracteres"
         << "del nuevo vector (con el mismo terminador)" << endl;

    // Lectura

    car = cin.get();
    i = 0;

    while (car != TERMINADOR) {
        v[i] = car;
        car = cin.get();
        i++;
    }

    util_v = i;

    car = cin.get();
    i = 0;

    while (car != TERMINADOR) {
        nuevo[i] = car;
        car = cin.get();
        i++;
    }

    util_nuevo = i;

    a_borrar = cin.get();


    //Calculamos el numero de ocurrencias de a_borrar
    for (int j = 0; j < util_v; j++){
        if (v[j] == a_borrar)
            num_ocurrencias++;
    }



    //////////////////////////////////////////////////////////
    // Incluya aquí el código para resolver el problema
    //////////////////////////////////////////////////////////

    int lec=0, esc=0;

    lec = util_v-1;                                 //Calculamos la posicion en la que va a empezar a leer vlores de v
    esc = lec + num_ocurrencias * (util_nuevo - 1); //Calculamos el numero de utiles totales que tendra v
    util_v = esc+1;

    while(lec >= 0){
        //Si existe el elemento a borrar
        if (v[lec] == a_borrar){
            //Insertamos al final el vector a insertar 
            for (int j=util_nuevo-1; j >= 0; j--) {
                v[esc] = nuevo[j];
                esc--;
            }
        } else {
            //Sustituimos el caracter != a_borrar en la posicion de escritura 
            v[esc] = v[lec];
            esc--;
        }
        lec--;
    }


    cout << "<";

    for (int i = 0; i < util_v; i++)
        cout << v[i];

    cout << ">" << endl;

    //unoadosaa#TTU#a
}
