//Alberto Llamas Gonzalez

// Elasticidad Precio-Demanda

#include <iostream>
#include <cmath>
using namespace std;

//////////////////////////////////////////////////////////////
// Defina aquí las funciones que sean necesarias
//////////////////////////////////////////////////////////////

double VariacionPorcentual(double inicial, double final){
    return abs(100 * (final - inicial) / inicial);
}

double ElasticidadPrecioDemanda(double precio_ini, double precio_fin, double demanda_ini, double demanda_fin){

    double variacion_precio = 0, variacion_demanda = 0, elasticidadPrecioDemanda = 0;

    variacion_precio = VariacionPorcentual(precio_ini, precio_fin);
    variacion_demanda = VariacionPorcentual(demanda_ini, demanda_fin);

    elasticidadPrecioDemanda = variacion_demanda / variacion_precio;

    return elasticidadPrecioDemanda;
}

int main() {
    double precio_ini, precio_fin;
    double demanda_ini, demanda_fin;
    double elast_pd = 0;

    cout << "Cálculo de la Elasticidad Precio-Demanda.\n\n"
         << "Introduzca cuaternas de valores:"
         << "El precio inicial, el precio final, la demanda inicial y la demanda final.\n"
         << "Introduzca cualquier negativo en el precio inicial para terminar\n\n";

    cin >> precio_ini;

    while (precio_ini >= 0){
        cin >> precio_fin;
        cin >> demanda_ini;
        cin >> demanda_fin;

        //////////////////////////////////////////////////////////////
        // Calcule aquí el valor de la variable elast_pd
        //////////////////////////////////////////////////////////////

        elast_pd = ElasticidadPrecioDemanda(precio_ini, precio_fin, demanda_ini, demanda_fin);

        cout << "Elasticidad Precio-Demanda: " << elast_pd << "\n";
        cin >> precio_ini;
    }
}
