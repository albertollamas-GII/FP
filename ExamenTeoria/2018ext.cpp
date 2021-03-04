//2018 EXTRAORDINARIA
#include <iostream>
#include <limits>

using namespace std;

// int main(){

//     int n;
//     int C[n][n];
//     int ciudad_inicial;
//     cin >> ciudad_inicial;
//     bool ya_visitada[n];
//     for (int i = 0; i < n; i++)
//         ya_visitada[i] = false;
//     int num_visitadas;
//     int minimo = numeric_limits<int>::max();
//     int actual = ciudad_inicial;
//     int coste_total;

//     while (num_visitadas < n){
//         for(int col= 0; col < n; col++){
//             if (C[actual][col] < minimo && !ya_visitada[actual])
//                 minimo = C[actual][col];
//         }
//         ya_visitada[actual] = true;
//         coste_total += minimo;
//         num_visitadas++;
//         actual++;

//         if (actual == n)
//             actual = actual % n;
//     }    
// }

int NumeroRepeticiones(char a){
    int repeticiones = 0;
    for (int i = 0; i < TotalUtilizados(); i++){
        if (Elemento(i) == a)
            repeticiones++;
    }
    return repeticiones;
}

int GradoPalabra(){
    int grado = 0;
    const int MINUSCULAS = 'a' -'z' +1;
    
    bool visitado[MINUSCULAS];
    
    int minimo = numeric_limits<int>::max();
    int maximo = numeric_limits<int>::min();

    for (int i = 0; i < TotalUtilizados(); i++){
        int ocurrencias = NumeroRepeticiones(Elemento(i));
        if (!visitado[vp[i]-'a']){
            if (minimo > ocurrencias){
            minimo = ocurrencias;
            }

            if (maximo < ocurrencias){
                maximo = ocurrencias;
            }
            visitado[vp[i]-'a'] = true;
        }
    }

    return maximo - minimo;
}


