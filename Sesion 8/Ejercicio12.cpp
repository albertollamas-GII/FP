//Alberto Llamas Gonzalez

#include <iostream>
using namespace std;

int main() {
   const char TERMINADOR = '#';
   const int MAX_NUM_CARACT = 3e6; // Compile con la opción -Wl,--stack,21000000
   char v[MAX_NUM_CARACT];
   char a_borrar;
   char car;
   int i, util, pos_lectura, pos_escritura;

   // Lectura

   car = cin.get();
   i = 0;

   while (car != TERMINADOR) {
      v[i] = car;
      car = cin.get();
      i++;
   }

   util = i;
   a_borrar = cin.get();

   ////////////////////////////////////////////////
   // Aquí debe completar el código para eliminar
   // el carácter "a_borrar" del vector "v"
   ////////////////////////////////////////////////

   for (pos_lectura = 0; pos_lectura < util; pos_lectura++){
      if (v[pos_lectura] != a_borrar){
         v[pos_escritura] = v[pos_lectura];
         pos_escritura++;
      }
   }
   
   util = pos_escritura;

   for (int i = 0; i < util; i++)
      cout << v[i];

}
