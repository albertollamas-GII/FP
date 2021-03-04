//Alberto Llamas Gonzalez
#include <iostream>

using namespace std;

class Dinero {
public:
    int euros, centimos;

    void SetEurCent(int euros, int centimos){
        int euros_aux = euros;
        int centimos_aux = centimos;

        while(centimos >= 100){
            centimos_aux = centimos % 100;
            centimos /= 100;
            euros_aux++;
        }

        this->euros = euros_aux;
        this->centimos = centimos_aux;
    }

};

int main(){

    int euros1, euros2, centimos1, centimos2;
    int suma_euros, suma_centimos;
    Dinero dinero1, dinero2, suma;

    cout << "\nIntroduzca euros y centimos de la persona 1: ";
    cin >> euros1 >> centimos1;

    cout << "\nIntroduzca euros y centimos de la persona 2 para calcular su suma: ";

    cin >> euros2 >> centimos2;

    dinero1.SetEurCent(euros1, centimos1);
    dinero2.SetEurCent(euros2, centimos2);

    suma_euros = dinero1.euros + dinero2.euros;
    suma_centimos = dinero1.centimos + dinero2.centimos;

    suma.SetEurCent(suma_euros, suma_centimos);

    cout << endl << "La suma es " << suma.euros << " euros y " << suma.centimos << " centimos." << endl;
    


}