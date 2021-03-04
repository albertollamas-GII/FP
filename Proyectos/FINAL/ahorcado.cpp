/**
  * @file ahorcado.cpp
  * @brief Programa para jugar al ahorcado en consola
  *
  * @author Alberto Llamas Gonzalez (Grupo 6)
  * @date Enero-2020
  *
  * El programa implementa una version basica del juego del ahorcado como
  * ejercicio de uso de clases simples.
  * 
  * 
  * */

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

class Ahorcado{
private:
   static const int MAX_LETRAS = 27;
   string incognita;
   string incognita_guiones;
   int num_intentos;
   char letras[MAX_LETRAS];
   int util_letras;

   //Metodo que deja el vector de char vacío
   void vaciarLetrasErroneas(){
      for (int i = 0; i < util_letras; i++)
         letras[i] = '\0';
   }

public:

   //Constructor con parametros 
   Ahorcado(string incognita){
      this->incognita = incognita;
      incognita_guiones = Guiones(this->incognita.size());
      num_intentos = 7;
      util_letras = 0;
      vaciarLetrasErroneas();
      
   }

   //Devuelve el numero de letras de la incognita
   int tamIncognita(){
      return incognita.size();
   }

   //Funcion que pasa un vector de char a string
   string ToString (char cstring[]){
      string cadena;
      cadena.reserve(MAX_LETRAS);

      for (int i = 0; i < MAX_LETRAS; i++){
         cadena.push_back(toupper(cstring[i]));
      }

      return cadena;
   }

   //Dada una letra guarda en el vector de letras erroneas la letra y aumenta su tamaño
   void setLetras(char letra){
      letras[util_letras] = letra;
      util_letras++;
   }

   //Metodo que nos dice si un char dado es una letra o no
   bool letraValida(char letra){
      bool es_valida = true;

      if (util_letras == 0)
         es_valida = true;
      
      if ((letra < 65 && letra != 35) || letra  > 90)
         es_valida = false;

      return es_valida;
   }

   //Nos dice si hemos acertado antes esa letra
   bool yaAcertada(char letra){
      bool yaAcertada = false;
      for (int i = 0; i < incognita_guiones.size() && !yaAcertada; i++){
         if (incognita_guiones[i] == letra)
            yaAcertada = true;
      }
      return yaAcertada;
   }

   //Nos dice si nos hemos equivocado ya con dicha letra
   bool usadaAnteriormenteLetras(char letra){
      bool usada = false;
      for (int i = 0; i < util_letras && !usada; i++){
         if (letras[i] == letra)
            usada = true;
      }

      return usada;
   }

   //Devuelve el numero de intentos
   int getNumIntentos(){
      return num_intentos;
   }

   //Devuelve el numero de letras erradas
   int getNumLetrasErradas(){
      return util_letras;
   }

   //Devuelve la letra erronea dada una posicion
   char getLetras(int i){
      return letras[i];
   }

   //Nos dice si una letra está en la incognita
   bool estaLetra(char letra){
      bool estaLetra = false;
      for (int i = 0; i < tamIncognita() && !estaLetra; i++){
         if (incognita[i] == letra)
            estaLetra = true;
      }
      return estaLetra;
   }

   //Asigna el numero de intentos
   void setNumIntentos(int numero){
      num_intentos = numero;
   }

   //Devuelve un string de guiones dado el numero de letras de la palabra
   string Guiones(int tamanio){
      string palabra_guiones;
      for (int i = 0; i < tamanio; i++)
         palabra_guiones.push_back('-');
      return palabra_guiones;
   }

   //Devuelve la incognita
   string getIncognita(){
      return incognita;
   }

   //Devuelve la palabra con guiones
   string getPalabraGuiones(){
      return incognita_guiones;
   }

   //Metodo que inserta una letra en la palabra con guiones
   string insertarLetraEnGuiones(char letra){
      int posicion = 0; bool esta = false;
      for (int i = 0; i < tamIncognita(); i++){
         if (incognita[i] == letra){
            this->incognita_guiones[i] = letra;
         }
      }
      return incognita_guiones;

   }

   //Nos dice si se ha ganado o no la partida, es decir si la palabra con guiones es la incognita
   bool victoriaMagistral(){
      bool victoriamagistral = false;

      if (incognita_guiones == incognita && num_intentos != 0)
         victoriamagistral = true;
      return victoriamagistral;
   }
};

//Clase cronometro para medir la duracion de la partida
class Cronometro{
   private:
      int tiempo_inicial;
      int tiempo_final;
   public:
      Cronometro(){
         resetCrono();
      }

      int getTiempoFinal(){
         return tiempo_final;
      }

      int getTiempoInicial(){
         return tiempo_inicial;
      }

      //Calcula el tiempo que se tarda en jugar
      int diferenciaIniFini(){
         calculaFinal();
         return tiempo_final - tiempo_inicial;
      }

      void calculaFinal(){
         tiempo_final = time(0);
      }

      //Resetea el tiempo a time
      void resetCrono(){
         tiempo_final = tiempo_inicial = time(0);
      }


};


int main(){
   const int MAX_LETRAS = 27;
   const char FINALIZA_PARTIDAS = '#';
   Bolsa bolsa;
   Cronometro crono;

   int aleatorio = rand() % bolsa.getNumPalabras();

   cout << "\n\n";
   int num_partidas = 0;

   cout << "\n******JUEGO DEL AHORCADO******" << endl;
   cout << "Normas: " << endl;;
   cout << "1.-Tiene 3 minutos por partida" << endl;
   cout << "2.-Puede introducir la letra en mayuscula o en minuscula" << endl;
   cout << "3.-Tiene 7 intentos por partida" << endl;
   cout << "4.-Las palabras a acertar estan relacionadas con el Quijote" << endl;
   cout << "5.-Si mientras esta jugando se cansa, introduzca '#' para finalizar la partida" << endl;

   cout << "\n¿Cuantas partidas quiere jugar? ";
   cin >> num_partidas;
   int k = 0;

   //Bucle para que juegue el usuario las partidas deseadas
   while (k < num_partidas){
      cout << "\n******PARTIDA " << k+1 << "******" << endl;
      //Calculamos la posicion de la palabra y nos aseguramos de que no supere el numero de palabras
      int posicion = (aleatorio + k) % bolsa.getNumPalabras();

      //Creamos un objeto de la clase Ahorcado con la palabra
      Ahorcado juego(bolsa.getPalabra(posicion));

      int util_letras = 0;
      bool fin_partida = juego.victoriaMagistral();

      cout << "\nLa palabra a adivinar es: " << endl;
      cout << juego.getPalabraGuiones() << " con " << juego.tamIncognita() << " letras. " << endl;
      cout << "Tiene " << juego.getNumIntentos() << " intentos. " << endl;

      int intentos = juego.getNumIntentos();
      char letra;

      //Estas lineas de codigo comentadas, muestran la palabra a adivinar (para facilitar manejo de errores)
      // cout << endl
      //      << posicion << " " << bolsa.getPalabra(posicion) << endl;

      // cout << endl
      //      << juego.getIncognita() << endl
      //      << juego.getPalabraGuiones() << endl;

      intentos = juego.getNumIntentos();
      k++;
      fin_partida = juego.victoriaMagistral();

      //Reseteamos el cronometro al principio de cada partida
      crono.resetCrono();
      int tiempoPartida = 0;

      while ((intentos > 0) && (!fin_partida) && tiempoPartida < 180){
         cout << "\nIntroduzca una letra para ver si esta: ";
         cin >> letra;

         //Vemos si el char introducido es una letra     
         while (!juego.letraValida(toupper((letra)))){
            cout << "\nCaracter incorrecto!, introduzca una letra valida: ";
            cin >> letra;
         }

         //Comprobamos si ya se ha introducido la letra
         while (juego.usadaAnteriormenteLetras(toupper(letra)) || juego.yaAcertada(toupper(letra))){
            cout << "\nYa has introducido esta letra antes!, introduce una letra nueva: ";
            cin >> letra;
         }

         //Si la letra es distinta a fin de partida
         if (letra != FINALIZA_PARTIDAS){
            //Si no esta la letra, la añadimos a las letras erroneas y restamos un intento
            if (!juego.estaLetra(toupper(letra))){
               juego.setLetras(toupper(letra));
               cout << "\nERROR, LA LETRA INTRODUCIDA NO ESTÁ EN LA PALABRA " << endl;
               intentos--;
               juego.setNumIntentos(intentos);
            }
            //Si la letra esta, la insertamos en la palabra con guiones
            else{
               cout << "\nLETRA ACERTADA" << endl;
               juego.insertarLetraEnGuiones(toupper(letra));
               cout << "\nSIGUE ASI!" << endl;
            }
            cout << "\nPALABRA: " << endl;
            cout << juego.getPalabraGuiones() << endl;

            //Mostramos el numero de intentos restantes
            cout << "\nTe quedan " << intentos << " intentos. ";

            //Mostramos las letras erradas
            if (juego.getNumLetrasErradas()){
               cout << "\nLetras erradas: ";
               for (int i = 0; i < juego.getNumLetrasErradas(); i++)
                  cout << juego.getLetras(i) << " ";
            }

            cout << "\n\n";

            //Comprobamos de nuevo si se ha ganado o no
            fin_partida = juego.victoriaMagistral();
            tiempoPartida = crono.diferenciaIniFini();
         } else {
            //Salimos de los bucles para acabar la partida
            fin_partida = true;
            k = num_partidas;
         }

      }
      //Si nos hemos quedado sin intentos, mostramos un mensaje de que se ha perdido la partida
      if (intentos == 0)
         cout << endl << "******HAS PERDIDO****** (MAXIMO NUMERO DE ERRORES ALCANZADO)" << endl;
      else if (tiempoPartida >= 180)
         cout << endl << "******HAS PERDIDO****** (HAS SUPERADO EL LIMITE DE TIEMPO, DATE MAS PRISA EN LA SIGUIENTE!)" << endl;
      else if (letra != '#')
         cout << "\nEnhorabuena, HAS GANADO!!" << endl;
      else
         cout << "\n******HAS DECIDIDO FINALIZAR LA PARTIDA******" << endl;

      cout << "\nLa palabra era: " << juego.getIncognita() << endl;
   }

   cout << "\n\n";
}
