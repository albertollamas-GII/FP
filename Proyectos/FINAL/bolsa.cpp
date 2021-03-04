#include <iostream>
#include <string>
#include <ctime>
#include <cassert>
#include <cstdlib>

using namespace std;

const string LISTA[] = {"CABALLERO", "DULCINEA", "HISTORIA", "ESCUDERO",
                        "ROCINANTE", "ADELANTE", "GOBERNADOR", "ANDANTES",
                        "VOLUNTAD", "CAPITULO", "MENESTER", "DONCELLA",
                        "CABALLERIA", "CASTILLO", "FERNANDO", "FINALMENTE",
                        "AVENTURA", "HERMOSURA", "PALABRAS", "GOBIERNO",
                        "INTENCION", "CARDENIO", "PENSAMIENTOS", "LUSCINDA",
                        "LAGRIMAS", "APOSENTO", "AVENTURAS", "QUISIERA",
                        "LIBERTAD", "DESGRACIA", "ENTENDIMIENTO", "PENSAMIENTO",
                        "LICENCIA", "MERCEDES", "SEMEJANTES", "SILENCIO",
                        "VALEROSO", "DONCELLAS", "LABRADOR", "CABALLERIAS",
                        "CRISTIANO", "CRISTIANOS", "DISCRETO", "HICIERON",
                        "LLEGARON", "QUISIERE", "ESPALDAS", "MUESTRAS",
                        "ESCUDEROS", "DISCURSO", "GRANDEZA", "ALTISIDORA",
                        "PRINCESA", "HACIENDO", "RENEGADO", "PROVECHO",
                        "QUEDARON", "RESOLUCION", "PRESENTE", "ENCANTADORES",
                        "ENAMORADO", "VALIENTE", "ENCANTADO", "MOLINO",
                        "LICENCIADO", "NECESIDAD", "RESPONDER", "DISCRECION",
                        "EJERCICIO", "HACIENDA", "POSADERO", "ROCINANTE",
                        "PRESENCIA", "HISTORIAS", "PRESENTES", "VERDADERO"};

class Bolsa{
private:
   static const int MAX_SIZE = 10000;
   string palabras[MAX_SIZE];
   int num_palabras;


   //Metodo auxiliar al que se le pasa un vector de string y baraja su contenido
   void Baraja(string cadena[]){
      srand(time(0));
      int numeroAleatorio1 = 0;
      int numeroAleatorio2 = 0;
      string auxiliar;

      for (int i = 0; i < num_palabras; i++){
         numeroAleatorio1 = (rand() % num_palabras);
         numeroAleatorio2 = (rand() % num_palabras);
         auxiliar = cadena[numeroAleatorio1];
         cadena[numeroAleatorio1] = cadena[numeroAleatorio2];
         cadena[numeroAleatorio2] = auxiliar;
      }
   }

public:

   //Constructor por defecto de la bolsa con palabras aleatorias del banco dado
   Bolsa(){
      num_palabras = sizeof(LISTA) / sizeof(string);

      for (int i = 0; i < num_palabras; i++){
         palabras[i] = LISTA[i];
      }
      Baraja(palabras);
   }

   //devuelve la palabra en la posicion dada
   string getPalabra(int posicion_aleatoria){
      assert(posicion_aleatoria < num_palabras);
      return palabras[posicion_aleatoria];
   }

   //Devuelve el numero de palabras
   int getNumPalabras(){
      return num_palabras;
   }

};