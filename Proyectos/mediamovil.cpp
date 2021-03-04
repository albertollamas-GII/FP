/**
  * @file media_movil.cpp
  * @brief Calcula la media movil de una secuencia de temperaturas
  *
  * @author Alberto Llamas Gonzalez
  * @date Diciembre-2020
  *
  * Escriba un programa que procesa una secuencia de valores de temperatura hasta que 
  * se introduce una temperatura menor que el cero absoluto  (-273.15 grados).
  * 
  * Como resultado, escribir� una secuencia de datos que corresponde a la media m�vil 
  * con tama�o N. Cada valor de la secuencia de esta media m�vil corresponde a:
  * 
  *    - La media de los primeros N datos desde el 0 al N-1,
  *    - la media de los N siguientes desde el 1 al N,
  *    - la media de los N siguientes desde el 2 al N+1,
  *    - etc.
  * 
  * Por tanto, si hay D datos, la secuencia resultado tendr� D-(N-1) valores. Esta 
  * secuencia, adem�s, estar� tambi�n terminada con un valor centinela.
  * 
  * El problema se puede resolver cargando toda la secuencia de datos y luego 
  * calculando la media m�vil para cada N datos, aunque tambi�n se podr�a limitar el 
  * tama�o de la memoria ocupada evitando tener toda la secuencia, pues s�lo es
  * necesario almacenar los �ltimos N valores.
  * 
  * Nota: En el problema, puede suponer que N es fijo y tiene un valor
  * predeterminado. As�, evita tener que introducirlo; tanto la entrada como la 
  * salida ser�n una simple secuencia.
  * 
  * Un ejemplo de ejecuci�n, con N valiendo 5, es:
  *     1 2 3 4 5 6 7 8 9 -300
  *     3 4 5 6 7 -300
  * donde la primera l�nea es la entrada y la segunda la salida.
  * 
  * Otra ejemplo, ahora con N valiendo 3, es:
  *     -0.04 -0.05 -0.09 -0.06 -0.07 -0.01 0.09 0.07 0.02 0.12 0.15 -300
  *     -0.06 -0.0666667 -0.0733333 -0.0466667 0.00333333 0.05 0.06 0.07 0.0966667 -300
  * 
  */

#include <iostream>

using namespace std;

int main(){
   const int MAX_SIZE = 10000;
   const double TERMINADOR = -273.15;
   const int N = 5;

   double temperatura[MAX_SIZE], media_movil[MAX_SIZE];
   int util_v = 0, i=0;
   double dato=0, suma = 0;

   cout << "\nIntroduzca la secuencias de temperaturas para calcular la media movil: ";
   cin >> dato;
   
   while (i < MAX_SIZE && dato > TERMINADOR) {
      temperatura[i] = dato;
      i++;
      cin >> dato;
   }

   util_v = i;

   // Si queremos hacer que se lea n 
   // cout << "\nIntroduzca n: ";
   // cin >> n;

   int aux=N;
   int num_valores_salida = util_v - (N-1);

   for (int i = 0; i < util_v; i++){
      suma=0;
      for (int j = i; j < aux; j++){
         suma += temperatura[j];
      }
      media_movil[i] = suma/N;
      aux++;
   }

   for (int i = 0; i < num_valores_salida; i++)
      cout << media_movil[i] << " ";

   cout << dato << endl;

   
}
