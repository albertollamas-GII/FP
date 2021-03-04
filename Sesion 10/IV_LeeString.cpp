//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// Lee string

#include <iostream>
#include <string>

using namespace std;

string LeeString(char terminador){
   string cadena;
   char caracter;
   
   caracter = cin.get();
   
   while (caracter != terminador){
      cadena.push_back(caracter);
      caracter = cin.get();
   }
   
   return cadena;
}

int main(){
   const char TERMINADOR = '@';
   char caracter, a_borrar;
   string cadena;
 
   // Lectura
   
   cout << "Lee string\n\n"
        << "Introduzca caracteres con terminador " << TERMINADOR << "\n";
        
   cadena = LeeString(TERMINADOR);

   cout << cadena;
}

