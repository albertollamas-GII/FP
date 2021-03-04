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
    SimuladorDeposito(double cap, double inter);
    void SetCapital(double cap);
    void SetCapital(double inter);
    double getCapital();
    double getInteres();
    int AniosHastaCantidad(double a_llegar);
    double CapitalTrasAnios(int anios);
};
