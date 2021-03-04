//Alberto Llamas Gonzalez

#include <iostream>
#include <string>

using namespace std;

double Potencia(double la_base, int el_exponente){

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

string EliminaUltimos(string original, char aEliminar){

    string eliminaultimos = "";

    while (original[original.size() - 1] == aEliminar && original != ""){
        original.erase(original.size() - 1);
    }

    eliminaultimos = original;

    return eliminaultimos;
}

string DoubleToString(double real, int num_decimal){

    double redondeado = Redondea(real, num_decimal);             //Redondeamos el num introducido

    string redondeado_string = to_string(redondeado);            //Pasamos a string
    redondeado_string=EliminaUltimos(redondeado_string, '0');    //Eliminamos los ceros del final
    redondeado_string = EliminaUltimos(redondeado_string, '.');  //Eliminamos el . en caso de que se introduzca 3.0 p.e
    
    return redondeado_string;
}

int main(){

    double real = 0.0; int numdecimales = 0;

    cout << "\nIntroduzca el numero real y el numero de cifras decimales: " ; 
    cin >> real >> numdecimales;

    string numero = DoubleToString(real, numdecimales);

    cout << "\nSe ha redondeado a " << numdecimales << " cifras decimales."
        <<  " Queda el siguiente numero con tipo de dato STRING " << numero << endl;
}