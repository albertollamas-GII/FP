//Alberto Llamas Gonzalez

#include <iostream>
#include <string>

using namespace std;

string EliminaUltimos(string original, char aEliminar){

    string eliminaultimos="";

    while (original[original.size()-1] == aEliminar && original != ""){
        original.erase(original.size()-1);
    }

    eliminaultimos = original;

    return eliminaultimos;

}

string LeeString(char terminador){
    string cadena;
    char caracter;

    caracter = cin.get();

    while (caracter != terminador){
        cadena.push_back(caracter);
        caracter = cin.get();
    }

    return cadena;
}

int main() {
    const char TERMINADOR = '#';
    string original;

    // Lectura

    cout << "Lee string\n\n"
         << "Introduzca caracteres con terminador " << TERMINADOR << "\n";

    original = LeeString(TERMINADOR);

    cout << "\nLa cadena introducida es " <<  original << endl;

    char eliminar = '\0';
    cout << "\nIntroduzca el caracter a eliminar: "; 
    cin >> eliminar;
    string eliminados = EliminaUltimos(original, eliminar);

    cout << "\nLa cadena sin el caracter " << eliminar << " al final es : " << eliminados << endl; 

}

/*
    ¿Cómo cambiaría la llamada en el main a la función EliminaUltimos 
    para modificar la cadena original con el resultado de quitarle los últimos caracteres?

    Deberiamos ahora llamar a EliminaUltimos(original, eliminados); Sin embargo, eliminados no es un char
    sino un string por lo que deberiamos crear un char por ejemplo:
    char eliminar[100];
    strcpy(eliminar, eliminados.c_str());

    Para tener el string resultante anterior en un char y poder llamar a la funcion. 
    Tambien podriamos hacer una sobrecarga de la funcion y tener EliminaUltimos(string, string);
*/
