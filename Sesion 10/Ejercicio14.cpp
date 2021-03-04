//Alberto Llamas Gonzalez

#include <iostream>
#include <string>

using namespace std;

string LeeString(char terminador){
    string cadena;
    char caracter;

    cout << "\nIntroduzca su mensaje inicial con el siguiente formato: " 
        << " [caracter][mensaje][terminador] " << endl;
    caracter = cin.get();

    while (caracter != terminador){
        cadena.push_back(caracter);
        caracter = cin.get();
    }

    return cadena;
}

void LineaCaracteres(int numCaracteres, char caracter){
    for (int i = 0; i < numCaracteres; i++)
        cout << caracter;
    
    cout << endl;
}

void MensajeInicial(string cadena){
    char caracter = cadena[0];
    int numCaracteres = cadena.size()-1;

    LineaCaracteres(numCaracteres, caracter);
    cadena.erase(0,1);

    cout << cadena << endl;

    LineaCaracteres(numCaracteres, caracter);

}

int main(){

    const char TERMINADOR = '@';
    string cadena = "";

    cadena = LeeString(TERMINADOR);
    MensajeInicial(cadena);

}