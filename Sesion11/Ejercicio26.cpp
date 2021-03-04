//Alberto Llamas Gonzalez

#include <iostream>
#include <cmath>

using namespace std;

class SimuladorDeposito{
private:
    double capital;
    double interes;
public:
    SimuladorDeposito();
    SimuladorDeposito(double cap, double inter){
        if (cap > 0 && inter >= 0){
            capital=cap;
            interes=inter;
        }
        else{
            capital = NAN;
            interes = NAN;
        }
    }
    void SetCapital(double cap){
        if (cap > 0){
            capital = cap;
        }
        else{
            capital = NAN;
        }
    }
    void SetInteres(double inter){
        if (inter >= 0)
            interes = inter;
        else
            interes = NAN;
    }
    double getCapital(){
        return capital;
    }
    double getInteres(){
        return interes;
    }
    int AniosHastaCantidad(double a_llegar){
        double aux_capital = capital;
        int anios = 0;
        while (aux_capital < a_llegar){
            aux_capital = capital * (pow(1 + interes / 100.0, anios + 1));
            anios++;
        }
        return anios;
    }
    double CapitalTrasAnios(int anios){
        double capital_final = 0;
        for (int i = 0; i < anios; i++){
            capital_final = capital * (pow(1 + interes / 100.0, i + 1));
        }
        return capital_final;
    }
};

int main(){
    SimuladorDeposito deposito1(300,5.4);
    const double A_LLEGAR = 2 * deposito1.getCapital();
    int anios = 0;

    cout << "\nEl capital y el interes inicial respectivamente son " << deposito1.getCapital() << " " << deposito1.getInteres() << endl;

    //Calcula los anios que deben pasar hasta que doble la cantidad fijada
    int anios_hasta_doblar = deposito1.AniosHastaCantidad(A_LLEGAR);
    cout << "\nPara que llegue a la cantidad " << A_LLEGAR << " deberan pasar " << anios_hasta_doblar << " anios." << endl;

    //Devuelve el capital tras pasar un numero de anios dado
    cout << "\nIntroduzca un numero de anios para ver su futuro capital: ";
    cin >> anios;

    double capital_futuro = deposito1.CapitalTrasAnios(anios);
    
    cout << "\nEl capital pasados " << anios << " anios sera " << capital_futuro << endl;

}