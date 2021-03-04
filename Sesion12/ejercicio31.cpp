//Alberto Llamas Gonzalez
// Elimina Ocurrencias Ineficiente
#include <string>
#include <iostream>
using namespace std;

// Incluya aqu� el c�digo de la clase SecuenciaCaracteres disponible en:
// https://decsai.ugr.es/jccubero/FP/IV_SecuenciaCaracteres.cpp

class SecuenciaCaracteres
{
private:
   static const int TAMANIO = 2e6; // 2e6 es un real (dos millones)
                                   // -> casting automático a int

   // Para poder dimensionar con un tamaño
   // tan grande, hay que cambiar unos parámetros
   // del compilador:
   // Herramientas -> Opciones del Compilador ->
   // Compilador -> Añadir las siguientes opciones
   // -Wl,--stack,26000000
   char v[TAMANIO];
   int util;

   void IntercambiaComponentesDirectamente(int pos_izda, int pos_dcha)
   {
      char intercambia;

      intercambia = v[pos_izda];
      v[pos_izda] = v[pos_dcha];
      v[pos_dcha] = intercambia;
   }

   bool EsCorrectaPosicion(int indice)
   {
      return 0 <= indice && indice < util;
   }

public:
   SecuenciaCaracteres()
       : util(0)
   {
   }

   int Utilizados()
   {
      return util;
   }

   int Capacidad()
   {
      return TAMANIO;
   }

   void EliminaTodos()
   {
      util = 0;
   }

   void Aniade(char nuevo)
   {
      if (util < TAMANIO)
      {
         v[util] = nuevo;
         util++;
      }
   }

   void Modifica(int posicion, char nuevo)
   {
      if (EsCorrectaPosicion(posicion))
         v[posicion] = nuevo;
   }

   char Elemento(int indice)
   {
      return v[indice];
   }

   string ToString()
   {
      // Si el número de caracteres en memoria es muy grande,
      // es mucho más eficiente reservar memoria previamente
      // y usar push_back

      string cadena;

      cadena.reserve(util);

      for (int i = 0; i < util; i++)
         cadena.push_back(v[i]);
      //cadena = cadena + v[i]  <- Evitarlo. Muy ineficiente para tamaños grandes;

      return cadena;
   }

   int PrimeraOcurrenciaEntre(int pos_izda, int pos_dcha, char buscado)
   {
      int i = pos_izda;
      bool encontrado = false;

      while (i <= pos_dcha && !encontrado)
         if (v[i] == buscado)
            encontrado = true;
         else
            i++;

      if (encontrado)
         return i;
      else
         return -1;
   }

   int PrimeraOcurrencia(char buscado)
   {
      return PrimeraOcurrenciaEntre(0, util - 1, buscado);
   }

   /////////////////////////////////////////////////////////////
   // Búsquedas

   // Precond: 0 <= izda <= dcha < util
   int PosMinimoEntre(int izda, int dcha)
   {
      int pos_minimo = -1;
      char minimo;

      minimo = v[izda];
      pos_minimo = izda;

      for (int i = izda + 1; i <= dcha; i++)
         if (v[i] < minimo)
         {
            minimo = v[i];
            pos_minimo = i;
         }

      return pos_minimo;
   }

   int PosMinimo()
   {
      return PosMinimoEntre(0, util - 1);
   }

   int BusquedaBinaria(char buscado)
   {
      int izda, dcha, centro;
      bool encontrado = false;

      izda = 0;
      dcha = util - 1;
      centro = (izda + dcha) / 2;

      while (izda <= dcha && !encontrado)
      {
         if (v[centro] == buscado)
            encontrado = true;
         else if (buscado < v[centro])
            dcha = centro - 1;
         else
            izda = centro + 1;

         centro = (izda + dcha) / 2;
      }

      if (encontrado)
         return centro;
      else
         return -1;
   }

   /////////////////////////////////////////////////////////////
   // Recorridos que modifican las componentes

   // Inserta un valor en la posición especificada
   void Inserta(int pos_insercion, char nuevo)
   {
      if (util < TAMANIO && pos_insercion >= 0 && pos_insercion <= util)
      {

         for (int i = util; i > pos_insercion; i--)
            v[i] = v[i - 1];

         v[pos_insercion] = nuevo;
         util++;
      }
   }

   // Elimina una componente, dada por su posición
   void Elimina(int posicion)
   {

      if (posicion >= 0 && posicion < util)
      {
         int tope = util - 1;

         for (int i = posicion; i < tope; i++)
            v[i] = v[i + 1];

         util--;
      }

   }

   /////////////////////////////////////////////////////////////
   // Algoritmos de ordenación

   void Ordena_por_Seleccion()
   {
      int pos_min;

      for (int izda = 0; izda < util; izda++)
      {
         pos_min = PosMinimoEntre(izda, util - 1);
         IntercambiaComponentesDirectamente(izda, pos_min);
      }
   }

   void Ordena_por_Insercion()
   {
      int izda, i;
      char a_desplazar;

      for (izda = 1; izda < util; izda++)
      {
         a_desplazar = v[izda];

         for (i = izda; i > 0 && a_desplazar < v[i - 1]; i--)
            v[i] = v[i - 1];

         v[i] = a_desplazar;
      }
   }

   void InsertaOrdenadamente(char nuevo)
   {
      int i;

      if (util > TAMANIO)
      {
         for (i = util; i > 0 && nuevo < v[i - 1]; i--)
            v[i] = v[i - 1];

         v[i] = nuevo;
         util++;
      }
   }

   void Ordena_por_Burbuja()
   {
      int izda, i;

      for (izda = 0; izda < util; izda++)
         for (i = util - 1; i > izda; i--)
            if (v[i] < v[i - 1])
               IntercambiaComponentesDirectamente(i, i - 1);
   }

   void Ordena_por_BurbujaMejorado()
   {
      int izda, i;
      bool cambio;

      cambio = true;

      for (izda = 0; izda < util && cambio; izda++)
      {
         cambio = false;

         for (i = util - 1; i > izda; i--)
            if (v[i] < v[i - 1])
            {
               IntercambiaComponentesDirectamente(i, i - 1);
               cambio = true;
            }
      }
   }

   void AniadeVarios(SecuenciaCaracteres nuevos)
   {
      int totales_a_aniadir = nuevos.Utilizados();

      for (int i = 0; i < totales_a_aniadir; i++)
         Aniade(nuevos.Elemento(i)); // Es importante entender
   }

   SecuenciaCaracteres ToUpper()
   {
      SecuenciaCaracteres en_mayuscula;

      for (int i = 0; i < util; i++)
         en_mayuscula.Aniade(toupper(v[i]));

      return en_mayuscula;
   }

   void EliminaOcurrencias(char a_borrar){
       int escr, lect;

       escr = 0;

       for (lect = 0; lect < util; lect++)
       {
           if (v[lect] != a_borrar)
           {
               v[escr] = v[lect];
               escr++;
           }
       }

       util = escr;
   }
   
};

int main(){
   const char TERMINADOR = '#';
   SecuenciaCaracteres secuencia;
   int total_leidos;
   int capacidad_secuencia;
   char caracter, a_borrar;

   capacidad_secuencia = secuencia.Capacidad();
   total_leidos = 0;
   caracter = cin.get();

   while (caracter != TERMINADOR && total_leidos < capacidad_secuencia){
      secuencia.Aniade(caracter);
      total_leidos++;
      caracter = cin.get();
   }
   
   cin >> a_borrar;
   
   // Incluya aqu� la llamada al m�todo EliminaOcurrencias
   secuencia.EliminaOcurrencias(a_borrar);
   cout << "\n\nCadena resultante: " << secuencia.ToString() << endl;
   
   /*
   En vez de poner
      cout << secuencia.ToString();
   podr�amos haber puesto:
      for (int i = 0; i < secuencia.Utilizados(); i++)
         cout  << secuencia.Elemento(i) << " ";
   pero queda m�s elegante la primera forma.
   */
}
/*
maaaovaiala#a
movil

aaaaa#a
vector vac�o
*/

