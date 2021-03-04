//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////


/*
En este ejercicio, no hay que construir ninguna clase ni
función. Es un ejercicio sobre recorridos de una matriz.
Leed desde teclado dos variables util_filas y util_columnas y leed los datos
de una matriz de enteros de tamaño util_filas x util_columnas. Sobre dicha
matriz, se pide lo siguiente:

a) Calcular la traspuesta de la matriz, almacenando el resultado en otra matriz.

d) Leer los datos de otra matriz y multiplicar ambas matrices (las dimensiones de la
segunda matriz han de ser compatibles con las de la primera para poder hacer la
multiplicación)
*/

#include <iostream>
using namespace std;

int main(){
   const int MAX_FIL = 10, MAX_COL = 10;
   double matr[MAX_FIL][MAX_COL];
   double trasp[MAX_COL][MAX_FIL];
   int util_fil, util_col;


   // No etiquetamos las entradas porque suponemos que leemos de un fichero
   // Supondremos que util_fil y util_col son > 0

   cin >> util_fil;
   cin >> util_col;

   for (int i=0; i<util_fil; i++)
      for (int j=0; j<util_col; j++)
         cin >> matr[i][j];

   ///////////////////////////////////////////////////////////////////////////
   // Traspuesta
   
   int util_fil_trasp, util_col_trasp;
   
   util_fil_trasp = util_col;
   util_col_trasp = util_fil;
   
   for (int i=0; i<util_fil_trasp; i++)
      for (int j=0; j<util_col_trasp; j++)
         trasp[i][j] = matr[j][i];
   
   cout << "\n\n";
   cout << "Matriz original:\n";

   for (int i=0; i<util_fil; i++){
      cout << "\n";

      for (int j=0; j<util_col; j++)
         cout << matr[i][j] << '\t';
   }
   
   cout << "\n\n";
   cout << "Matriz trasp:\n";   
    
   for (int i=0; i<util_fil_trasp; i++){
      cout << "\n";
      
      for (int j=0; j<util_col_trasp; j++)
         cout << trasp[i][j] << '\t';
   }  
}