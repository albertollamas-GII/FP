//Alberto Llamas Gonzalez

#include <iostream>
using namespace std;

const double MIN_TEMP = -90;        //Preguntar qué es mas correcto
const double MAX_TEMP = 60;

bool RangoCorrecto(double rango);

int main(){

    double act, ante;
    int long_act, long_mayor, pos_act, pos_ini, pos_ini_mayor;
    bool fin_input;

    cout << "Mayor secuencia ascendente de temperaturas\n\n";

    long_act = 1;
    long_mayor = 0;
    pos_ini_mayor = 1;
    pos_act = 1;
    pos_ini = 1;

    cin >> ante;
    fin_input = RangoCorrecto(ante);

    while (!fin_input){
        cin >> act;
        pos_act++;
        fin_input = RangoCorrecto(act);

        if (fin_input || act < ante){
            if (long_act > long_mayor){
                long_mayor = long_act;
                pos_ini_mayor = pos_ini;
            }

            long_act = 1;
            pos_ini = pos_act;
        }
        else
            long_act++;

        ante = act;
    }

    cout << "\nMayor subsecuencia: \nPosición de inicio -> " << pos_ini_mayor;
    cout << "\nLongitud -> " << long_mayor << endl;
}

bool RangoCorrecto(double rango){
    return (rango < MIN_TEMP || rango > MAX_TEMP);
}
