/**
  * @file mediana_movil.cpp
  * @brief Calcula la mediana movil de una secuencia de temperaturas
  *
  * @author Alberto Llamas Gonzalez (Grupo 6)
  * @date Diciembre-2020
  *
  * Escriba un programa que procesa una secuencia de valores de temperatura hasta que 
  * se introduce una temperatura menor que el cero absoluto  (-273.15 grados).
  * 
  * Como resultado, escribir� una secuencia de datos que corresponde a la mediana m�vil 
  * con tama�o N. Cada valor de la secuencia de esta mediana m�vil corresponde a:
  * 
  *    - La mediana de los primeros N datos desde el 0 al N-1,
  *    - la mediana de los N siguientes desde el 1 al N,
  *    - la mediana de los N siguientes desde el 2 al N+1,
  *    - etc.
  * 
  * Por tanto, si hay D datos, la secuencia resultado tendr� D-(N-1) valores. Esta 
  * secuencia, adem�s, estar� tambi�n terminada con un valor centinela.
  * 
  * El problema se puede resolver cargando toda la secuencia de datos y luego 
  * calculando la mediana m�vil para cada N datos, aunque tambi�n se podr�a limitar el 
  * tama�o de la memoria ocupada evitando tener toda la secuencia, pues s�lo es
  * necesario almacenar los �ltimos N valores.
  * 
  * Nota: En el problema, puede suponer que N es fijo y tiene un valor
  * predeterminado. As�, evita tener que introducirlo; tanto la entrada como la 
  * salida ser�n una simple secuencia.
  * 
  * Un ejemplo de ejecucion, con N valiendo 5, es:
  *     1 2 3 4 5 6 7 8 9 -300
  *     3 4 5 6 7 -300
  * donde la primera linea es la entrada y la segunda la salida.
  * 
  * Otra ejemplo, ahora con N valiendo 5, es:
  *     -0.4 -0.5 -0.9 -0.6 -0.7 -0.1 0.9 0.7 0.2 1.2 1.5 -300
  *     -0.6 -0.6 -0.6 -0.1 0.2 0.7 0.9 -300
  * 
  * El mismo ejemplo, ahora con N valiendo 3, es:
  *     -0.4 -0.5 -0.9 -0.6 -0.7 -0.1 0.9 0.7 0.2 1.2 1.5 -300
  *     -0.5 -0.6 -0.7 -0.6 -0.1 0.7 0.7 0.7 1.2 -300
  */

#include <iostream>

using namespace std;

int main(){
   const int MAX_SIZE = 10000;
   const double TERMINADOR = -273.15;
   const int N = 5;
   bool mediana_par = false;

   double temperatura[MAX_SIZE] = {0}, mediana_movil[MAX_SIZE] = {0}, aux_temp[MAX_SIZE] = {0};
   int util_v = 0, i = 0;
   double dato = 0, mediana = 0;

   cout << "\nIntroduzca la secuencias de temperaturas para calcular la mediana movil: ";
   cin >> dato;

   while (i < MAX_SIZE && dato > TERMINADOR){
      temperatura[i] = dato;
      i++;
      cin >> dato;
   }

   util_v = i;

   cout << "\n";


   // Si queremos hacer que se lea n
   // cout << "\nIntroduzca n: ";
   // cin >> n;

   //Comprobamos si el numero de datos es par o impar para calcular la mediana correctamente
   if (N % 2 == 0)
      mediana_par = true;
   
   int aux = N;
   int num_valores_salida = util_v - (N - 1);

   int posicion_mediana = 0;
   double minimo = 0, intercambia = 0;
   int posicion_minimo = 0;

   //Recorremos el vector
   for (int k = 0; k < util_v; k++){
      //Introducimos los N-1, N, ... primeros elementos en aux para calcular la mediana
      for (int i = k; i < aux; i++)
         aux_temp[i] = temperatura[i];

      //Recorremos el vector desde 0 hasta N-1, 1 hasta N, ...
      for (int i = k; i < aux; i++){
         //Aplicamos el algoritmo de ordenacion por seleccion
         minimo = aux_temp[i];
         posicion_minimo = i;

         for (int j = i+1; j < aux; j++){
            if (aux_temp[j] < minimo){
               minimo = aux_temp[j];
               posicion_minimo = j;
            }
         }
         intercambia = aux_temp[i];
         aux_temp[i] = aux_temp[posicion_minimo];
         aux_temp[posicion_minimo] = intercambia;
      }
      //Calculamos la mediana
      posicion_mediana = (k + aux) / 2;
      if (!mediana_par){
         mediana_movil[k] = aux_temp[posicion_mediana];
      } else {
         mediana_movil[k] = (temperatura[posicion_mediana] + aux_temp[posicion_mediana+1])/2;
      }
      aux++;
   }

   cout << "\n\nSalida: ";

   for (int i = 0; i < num_valores_salida; i++)
      cout << mediana_movil[i] << " ";

   cout << dato << endl;
}