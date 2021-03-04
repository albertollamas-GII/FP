//Alberto Llamas Gonzalez

#include <iostream>
#include <cmath>

using namespace std;

double Redondea(double num_real, int decimal);
double Potencia(double la_base, int el_exponente);


int main(){
    double real, real_redond, desplazamiento;
    int num_decim;

    cout << "Round con cualquier número de cifras"
         << "\nIntroduzca el número real y el número de cifras decimales:\n";
    cin >> real;
    cin >> num_decim;

    real_redond = Redondea(real,num_decim);

    cout << "\nResultado: " << real_redond << "\n\n";
}



double Potencia(double la_base, int el_exponente) {

    double potencia;
    int exponente_positivo;

    exponente_positivo = abs(el_exponente);
    potencia = 1;

    for (int i = 1; i <= exponente_positivo; i++)
        potencia = potencia * la_base;

    if (el_exponente < 0)
        potencia = 1 / potencia;

    return potencia;
}


double Redondea(double num_real, int decimal){

    double desplazamiento, real_redond;

    desplazamiento = Potencia(10, decimal);
    real_redond = round(num_real * desplazamiento);
    real_redond = real_redond / desplazamiento;

    return real_redond;
}
