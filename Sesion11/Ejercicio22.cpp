//Alberto Llamas Gonzalez

#include <iostream>

using namespace std;

class Instante{
private:
    int horas;
    int minutos;
    int segundos;
public:
    //COnstructores
    Instante(){
        horas=0;
        minutos=0;
        segundos=0;
    }
    Instante(int horas, int minutos, int segundos){
        this->horas = horas;
        this->minutos = minutos;
        this->segundos = segundos;
    }
    //Getters
    int getSegundos();
    int getHoras();
    int getMinutos();
    //Obtener el numero de segundos totales
    int SegundosTotales();
    //Obtener el numero de minutos totales
    int MinutosTotales();
    //Modificadores
    int setSegundos(int segundos);
    int setHoras(int horas);
    int setMinutos(int minutos);
    //Dado un numero de segundos establece el instante en el que nos encontremos
    void SetSegundosTotales(int segundos);
};

int main(){
    Instante instant(1,2,5);
    
    cout << instant.SegundosTotales();
    cout << instant.MinutosTotales();

    instant.SetSegundosTotales(3725);
}