/**
  * @file diccionario.cpp
  * @brief Programa para listar un diccionario tras barajar
  *
  * @author Alberto Llamas Gonzalez
  * @date Diciembre-2020
  *
  * El programa es un ejemplo de uso de string y vectores-C con n�meros aleatorios
  * 
  * El programa no usar� el tipo vector de char, aunque s� el vector-C con objetos de
  * tipo string. Deber� crear un vector con el siguiente contenido:
  *       "caballero",  "Dulcinea",   "historia",   "escudero",
  *       "rocinante",  "adelante",   "gobernador", "andantes", 
  *       "voluntad",   "capitulo",   "menester",   "doncella", 
  *       "caballeria", "castillo",   "Fernando",   "finalmente", 
  *       "aventura",   "hermosura",  "palabras",   "gobierno", 
  *       "intencion",  "cardenio",   "pensamientos", "Luscinda",
  *       "lagrimas",   "aposento",   "aventuras",  "quisiera", 
  *       "libertad",   "desgracia",  "entendimiento", "pensamiento", 
  *       "licencia",   "Mercedes",   "semejantes", "silencio", 
  *       "valeroso",   "doncellas",  "labrador",   "caballerias", 
  *       "cristiano",  "cristianos", "discreto",   "hicieron", 
  *       "llegaron",   "quisiere",   "espaldas",   "muestras", 
  *       "escuderos",  "discurso",   "grandeza",   "altisidora",
  *       "princesa",   "haciendo",   "renegado",   "provecho",
  *       "quedaron",   "resolucion", "presente",   "encantadores",
  *       "enamorado",  "valiente",   "encantado",  "molino",
  *       "licenciado", "necesidad",  "responder",  "discrecion", 
  *       "ejercicio",  "hacienda",   "posadero",   "rocinante",
  *       "presencia",  "historias",  "presentes",  "verdadero"
  * 
  * A continuaci�n, deber� barajar las entradas del vector. Para ello, puede hacer tantos
  * intercambios como palabras tiene el diccionario. Un intercambio consiste en seleccionar
  * dos posiciones e intercambiar los contenidos de las dos casillas del vector.
  * 
  * Finalmente, tendr� que listar el nuevo diccionario, con las mismas palabra pero en
  * distinto orden. Adem�s, para cada palabra, debe dibujar tantos guiones como letras tenga
  * debajo. Por ejemplo, el listado puede comenzar as�:
  *       1.- caballero
  *           ---------
  *       2.- Dulcinea
  *           --------
  *       3.- valiente
  *           --------
  *       4.- valeroso
  *           --------
  * 
  * y terminar:
  *       74.- licenciado
  *            ----------
  *       75.- escudero
  *            --------
  *       76.- provecho
  *            --------
  * 
  */

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int NumeroDigitos(int numero){
   int numerodigitos = 0;
   while(numero > 0){
      numero = numero / 10;
      numerodigitos++;
   }
   return numerodigitos;
}

void LineaCaracteres(int numCaracteres, char caracter, int indice){
   const string ESPACIO_DEF = "   ";
   cout << ESPACIO_DEF;
   for (int i = 0; i < indice; i++)
      cout << " ";
   for (int i = 0; i < numCaracteres; i++)
      cout << caracter;

   cout << endl;
}


int main(){

   string cadena[] = {"caballero", "Dulcinea", "historia", "escudero",
                              "rocinante", "adelante", "gobernador", "andantes",
                              "voluntad", "capitulo", "menester", "doncella",
                              "caballeria", "castillo", "Fernando", "finalmente",
                              "aventura", "hermosura", "palabras", "gobierno",
                              "intencion", "cardenio", "pensamientos", "Luscinda",
                              "lagrimas", "aposento", "aventuras", "quisiera",
                              "libertad", "desgracia", "entendimiento", "pensamiento",
                              "licencia", "Mercedes", "semejantes", "silencio",
                              "valeroso", "doncellas", "labrador", "caballerias",
                              "cristiano", "cristianos", "discreto", "hicieron",
                              "llegaron", "quisiere", "espaldas", "muestras",
                              "escuderos", "discurso", "grandeza", "altisidora",
                              "princesa", "haciendo", "renegado", "provecho",
                              "quedaron", "resolucion", "presente", "encantadores",
                              "enamorado", "valiente", "encantado", "molino",
                              "licenciado", "necesidad", "responder", "discrecion",
                              "ejercicio", "hacienda", "posadero", "rocinante",
                              "presencia", "historias", "presentes", "verdadero"};

   int util_cad = sizeof(cadena) / sizeof(string);
   string auxiliar;

   srand(time(0));
   int numeroAleatorio1 = 0;
   int numeroAleatorio2 = 0;

   for (int i = 0; i < util_cad; i++){
      numeroAleatorio1 = (rand() % util_cad);
      numeroAleatorio2 = (rand() % util_cad);
      auxiliar = cadena[numeroAleatorio1];
      cadena[numeroAleatorio1] = cadena[numeroAleatorio2];
      cadena[numeroAleatorio2] = auxiliar;
   }
   

   for (int i = 0; i < util_cad; i++){
      cout << i+1 << ".- " << cadena[i] << endl;
      LineaCaracteres(cadena[i].size(), '-', NumeroDigitos(i+1));
   }

}
