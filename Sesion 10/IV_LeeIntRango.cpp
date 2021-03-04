//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// Funci�n para leer un entero en un rango

/*
 Defina una funci�n LeeIntRango para leer un n�mero entero
obligando a que est� en un rango [min, max] . Para ello, dicha funci�n debe ir le-
yendo n�meros enteros (de tipo int ) desde la entrada por defecto, hasta que se lea
un valor que pertenezca al rango [min, max] (no hay ning�n l�mite en el n�mero de
intentos). La funci�n devolver� dicho valor.
Escriba un peque�o programa de prueba que lea dos n�meros min y max . El valor
de min puede ser cualquiera y supondremos que el valor introducido de max es co-
rrecto, es decir, que ser� mayor o igual que min . A continuaci�n llame a la funci�n
LeeIntRango tres veces para leer tres valores en el rango [min,max] y finalmente
calcule la suma de dichos valores.
Ejemplo de entrada: 3 6 -1 2 3 7 2 1 4 4 -- Salida correcta: 11
Ejemplo de entrada: 3 6 3 4 4 -- Salida correcta: 11
*/

#include <iostream>  
using namespace std; 

int LeeIntRango(int min, int max, string mensaje) {
   int a_leer;
   
   do{
      cout << mensaje;
      cin >> a_leer;
   }while (min > a_leer || max < a_leer);
   
   return a_leer;
}

int main(){
   const int TOTAL_A_INTRODUCIR = 3;
   
   long min, max, dato, suma;
   
   cout << "Programa de prueba para la funcion LeeIntRango"
        << "\nIntroduzca el valor minimo y el maximo"
        << "\nA continuacion introduzca "
        << TOTAL_A_INTRODUCIR << " enteros en el rango anterior\n";
        
   cin >> min;
   cin >> max;
   suma = 0;
   
   for (int i = 0; i < TOTAL_A_INTRODUCIR; i++){
      dato = LeeIntRango(min, max, "");
      suma = suma + dato;
   }

   cout << "\n\nSuma total: " << suma << endl;
}
