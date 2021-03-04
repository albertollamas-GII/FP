/*
Programa que recopila todos los algoritmos de recorrido, ordenacion
y busqueda en vectores. Por orden de codigo:
  -Busqueda de un elemento
  -Busqueda del minimo
  -Vector dentro de otro
  -Insertar un valor
  -Eliminar un valor
  - Algortimos de ordenacion:
    -Burbuja
    -Insercion
    -Seleccion
*/

#include <iostream>

using namespace std;

int main () {

   const int MAX_LONG = 20;
   int vector [MAX_LONG] = {0};
   int longitud;

   cout << "\nLongitud";
   cin >> longitud;

   cout << "\nVector: ";
   for (int i = 0; i < longitud; i++)
      cin >> vector[i];

   cout << "\nSalida del vector: ";
   for (int j = 0; j < longitud; j++)
      cout << vector[j] << " ";

   // Busqueda secuencial, algoritmo de primera ocurrencia
   int elemento;

   cout << "\nElemento a buscar: " ;
   cin >> elemento;

   int posicion_encontrado = -1;
   bool encontrado = false;
   int k= 0;

   while (k < longitud && !encontrado){
      if (vector [k] == elemento){
         encontrado = true;
         posicion_encontrado = k;
      }
      else
         k++;
   }

   if (encontrado)
      cout << "\nEsta en la posicion " << posicion_encontrado;
   else
      cout << "\nNo se encuentra.";

   //Busqueda del minimo en un vector

   int minimo;
   int posicion_minimo;

   if (longitud > 0){
      minimo = vector[0];
      posicion_minimo = 0;
      for (int i= 0; i < longitud; i++){
         if (vector[i] < minimo){
            minimo = vector[i];
            posicion_minimo = i;
         }
      }
   }
   else
      posicion_minimo = -1;

   cout << "\nposicion minimo: " << posicion_minimo;
   cout << "\nminimo: " << minimo;

   // Vector dentro de otro
   bool encontrado2;
   int longitud_subvector, posicion_encontrado2= 0;
   int subvector[MAX_LONG];
   bool va_coincidiendo;

   cout << "\nLongitud subvector: ";
   cin >> longitud_subvector;

   cout<< "\nSubvector: " ;
   for (int i = 0; i < longitud_subvector; i++)
      cin >> subvector[i];

   for (int inicio = 0; inicio + longitud_subvector <= longitud && !encontrado2; inicio++) {
      va_coincidiendo = true;
      for (int i = 0; i < longitud_subvector && va_coincidiendo; i++)
         va_coincidiendo = vector [inicio + i] == subvector[i];


      if (va_coincidiendo){
         encontrado2 = true;
         posicion_encontrado2 = inicio;
      }
   }

   if (encontrado2)
      cout << "\nEsta en la posicion " << posicion_encontrado2;
   else
      cout << "\n No se encuentra,";

   //Insertar un valor
   int nuevo_elemento;
   int nueva_posicion;
   cout << "\nPosicion a insertar nuevo valor:";
   cin >> nueva_posicion;

   cout << "\nValor a insertar: ";
   cin >> nuevo_elemento;
   if (longitud < MAX_LONG){
      for (int i = longitud; i > nueva_posicion; i--)
         vector [i] = vector [i-1];

      vector[nueva_posicion] = nuevo_elemento;
      longitud++;

      cout << "\nNuevo vector:";
      for (int i = 0; i < longitud; i++)
         cout << vector [i] << " ";
   }
  //Eliminar un valor
  int posicion_eliminar = 0;

  cout << "\nPosicion a eliminar elemento: ";
  cin >> posicion_eliminar;

  if (posicion_eliminar >= 0 && posicion_eliminar < longitud){
    int tope = longitud - 1;

    for (int i = posicion_eliminar; i < tope; i++)
      vector [i] = vector[i+1];

    longitud--;
  }

  cout << "\nNuevo vector:";
  for (int i = 0; i < longitud; i++)
     cout << vector [i];


  //Ordenacion por burbuja
  /*
  int intercambia;

  for (int izda = 0; izda < longitud; izda++){
    for (int j =longitud-1; j > izda; j--){
      if (vector[j] < vector[j-1]){
        intercambia = vector[j];
        vector[j] = vector[j-1];
        vector[j-1] = intercambia;
      }
    }
  }

  cout << "\nNuevo vector:";
  for (int i = 0; i < longitud; i++)
     cout << vector [i] << " ";
  */

  //Ordenacion por insercion
  /*
  int a_desplazar, p;

  for (int izda = 1; izda < longitud; izda++){
    a_desplazar = vector[izda];

    for (p =izda; p > 0 && a_desplazar < vector[p-1]; p--)
      vector[p] = vector[p-1];

    vector[p] = a_desplazar;
  }

  cout << "\nNuevo vector:";
  for (int i = 0; i < longitud; i++)
     cout << vector [i] << " ";
  */

  //Ordenacion por seleccion
  int minimo_ordenar, posicion_minimo_ordenar, intercambia;

  for (int izda = 0; izda < longitud; izda++){
    minimo_ordenar = vector[izda];
    posicion_minimo_ordenar = izda;

    for (int i=izda; i < longitud; i++){
      if (vector[i] < minimo_ordenar){
        minimo_ordenar = vector[i];
        posicion_minimo_ordenar = i;
      }
    }
    intercambia = vector[izda];
    vector[izda] = vector[posicion_minimo_ordenar];
    vector[posicion_minimo_ordenar] = intercambia;
  }

  cout << "\nNuevo vector:";
  for (int i = 0; i < longitud; i++)
     cout << vector [i] << " " ;

  cout << endl;

  int vector2[MAX_LONG] = {0};
  int longitud2;
  cin >> longitud2;
  for (int t = 0; t < longitud2; t++)
      cin >> vector2[t];

  //Busqueda del maximo
  int posicion_maximo = 0;
  int maximo = 0;

  if (longitud2 > 0){
    posicion_maximo = 0;
    maximo = vector2[0];

    for (int t = 0; t < longitud2; t++){
      if (maximo < vector2[t]){
        maximo = vector2[t];
        posicion_maximo = t;
      }
    }
  }
  else
    posicion_maximo = -1;

  cout << "\n";
  cout << maximo << " en " << posicion_maximo;
}
