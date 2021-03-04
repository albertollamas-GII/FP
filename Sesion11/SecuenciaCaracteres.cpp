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
    SecuenciaCaracteres(){
        util_caracteres = 0;
    }
    void Aniade (char caracter){
        if (util_caracteres < TAM){
            caracteres[util_caracteres] = caracter;
            util_caracteres++;
        }
    }
    int Utilizados(){
        return util_caracteres;
    }
    void Invierte();
    char Elemento(int posicion){
        if (posicion < util_caracteres)
            return caracteres[posicion];
    }
    int PrimeraOcurrencia(char a_encontrar){
        bool encontrado = false;
        int pos = -1;
        for (int i = 0; i < util_caracteres && !encontrado; i++){
            if (caracteres[i] == a_encontrar){
                encontrado = true;
                pos = i;
            }
        }
        return pos;
    }
    void Elimina(int posicion){
        if (posicion >= 0 && posicion < util_caracteres){
            int tope = util_caracteres - 1;

            for (int i = posicion; i < tope; i++)
                caracteres[i] = caracteres[i + 1];

            util_caracteres--;
        }
    }
    void EliminaOcurrencias(char a_eliminar){
        for (int i = 0; i < util_caracteres; i++){
            if (caracteres[i] == a_eliminar){
                Elimina(i);
            }
        }
    }

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