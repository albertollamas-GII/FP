//Alberto Llamas Gonzalez

#include <iostream>

using namespace std;

class SecuenciaCaracteres{
private:
//Es más adecuada esta opción (sin terminador) ya que es menos restrictiva y más cómoda para ser utilizada
    static const int TAM = 100;
    char caracteres[TAM];
    int util_caracteres;

public:
    SecuenciaCaracteres();
    void Aniade (char caracter);
    int Utilizados();
    void Invierte();
    char Elemento(int posicion);
    int PrimeraOcurrencia(char a_encontrar);
    void Elimina(int posicion);
    void EliminaOcurrencias(char a_eliminar);

};

int main(){

    SecuenciaCaracteres cadena;

    cadena.Aniade('H');
    cadena.Aniade('o');
    cadena.Aniade('l');
    cadena.Aniade('a');

    int utilizados = cadena.Utilizados();

    cadena.Invierte();

    int posicionElemento = cadena.PrimeraOcurrencia('a');
    cadena.EliminaOcurrencias('H');
}