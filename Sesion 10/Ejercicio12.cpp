//Alberto Llamas Gonzalez

#include <iostream>
#include <cctype>
using namespace std;

const int LIMITE_KMS_RECARGO = 300;
const double RECARGO_KM = 0.1;
const double MIN_KMS_DSCTO = 700.0;
const int MIN_PTOS_DSCTO_BAJO = 100;
const int MIN_PTOS_DSCTO_ALTO = 200;
const int DSCTO_POR_KMS = 2;
const int DSCTO_BAJO_POR_PTOS = 3;
const int DSCTO_ALTO_POR_PTOS = 4;
const double TARIFA_BASE = 150.0;
const int MAX_PTOS = 400;

int LeeIntMayorOIgual(int entero){
    
    int distancia = 0;
    do{
        cin >> distancia;
    } while (distancia <= entero);

    return distancia;
}

int LeeIntRango(int minimo, int maximo){
    int ptos_fidel;
    do{
        cin >> ptos_fidel;
    } while (ptos_fidel < minimo || ptos_fidel > maximo);
    return ptos_fidel;
}

double CalculoTarifa(int distancia){
    double tarifa = TARIFA_BASE;
    if (distancia > LIMITE_KMS_RECARGO)
        tarifa = tarifa + RECARGO_KM * (distancia - LIMITE_KMS_RECARGO);
    
    return tarifa;
}

double CalculoDescuentoDistancia(int distancia){
    double dscto;
    if (distancia > MIN_KMS_DSCTO)
        dscto = DSCTO_POR_KMS;
    else
        dscto = 0;
    
    return dscto;
}

double CalculoDescuentoPuntos(int ptos_fidel){
    double dscto;

    if (ptos_fidel > MIN_PTOS_DSCTO_ALTO)
        dscto = dscto + DSCTO_ALTO_POR_PTOS;
    else if (ptos_fidel > MIN_PTOS_DSCTO_BAJO)
        dscto = dscto + DSCTO_BAJO_POR_PTOS;

    return dscto;
}

double CalculoTarifaConDescuento(double tarifa, double descuento){
    double trf;
    trf = tarifa * (1 - descuento / 100.0);
    return trf;
}

int main(){

    const char TERMINADOR = '#';
    const char NUEVO = 'N';
    bool billete_nuevo, car_ok, fin_input;
    char car;

    double dscto;
    double tarifa;
    int distancia;
    int ptos_fidel;

    cout << "Tarifa aérea."
         << "\nIntroduzca los datos de todos los billetes introduciendo, "
         << "previamente, el carácter N (Nuevo) Introduzca # para terminar."
         << "\nIntroduzca la distancia del recorrido del viaje (> 0) y el "
         << "número de puntos de la tarjeta de fidelización (entre 0 y "
         << MAX_PTOS << ":\n";

    do{
        do{
            cin >> car;
            car = toupper(car);
            billete_nuevo = car == NUEVO;
            fin_input = car == TERMINADOR;
            car_ok = billete_nuevo || fin_input;
        } while (!car_ok);

        if (!fin_input){
            distancia=LeeIntMayorOIgual(0);
            ptos_fidel=LeeIntRango(0,MAX_PTOS);
            tarifa = CalculoTarifa(distancia);
            dscto = CalculoDescuentoDistancia(distancia) + CalculoDescuentoPuntos(ptos_fidel);
            tarifa = CalculoTarifaConDescuento(tarifa, dscto);

            cout << "\n\nTarifa final aplicando los descuentos: ";
            cout << tarifa;
        }
    } while (!fin_input);

    cout << endl;
}