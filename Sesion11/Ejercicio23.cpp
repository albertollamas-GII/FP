//Alberto Llamas Gonzalez
#include <iostream>
#include <string>

using namespace std;

class FormateadorDoubles{
private:
    string delimitador_dcha;
    string delimitador_izda;
    char separador;
    int decimales;
    //Incluimos en metodos privados porque no vamos a necesitarlos fuera de la clase, unicamente para doubletostring
    double PotenciaEntera(double base, int exponente);
    double Redondea(double real, int num_decimales);
    string EliminaUltimos(string cadena, char a_borrar);
    string DoubleToString(double real);

public:
    FormateadorDoubles(); //strings a "" y decimales a 2 y separador = '.'
    FormateadorDoubles(string delimitador_izda, string delimitador_dcha);
    void setSeparadorComa();
    void setSeparadorPunto();
    void setNumeroDecimales(int decimales);

    string getCadena(double real);
};

int main(){
    FormateadorDoubles format("<", ">");
    double real = 0.12345678;
    string cadena;

    cadena = format.getCadena(real);
    format.setSeparadorComa();
    format.setNumeroDecimales(5);

    cadena=format.getCadena(real);
}