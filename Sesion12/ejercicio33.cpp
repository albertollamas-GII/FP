//Alberto Llamas Gonzalez
// T�nel

#include <iostream>
#include <cmath>
#include "IV_FormateadorDoubles.cpp"
#include "IV_Instante.cpp"

using namespace std;

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

class Tunel{
private:
   double distancia_km;
   
   static const int MAX_NUM_VEHICULOS = 100;
   string matriculas[MAX_NUM_VEHICULOS];
   int entradas[MAX_NUM_VEHICULOS];
   int salidas[MAX_NUM_VEHICULOS];
   int total_entradas = 0;
   
   static const int INSTANTE_NULO = -1;
   
   int estaMatricula(string matricula){
      bool esta = false;
      int pos = -1;
      for (int i = 0; i < total_entradas && !esta; i++){
         if (matriculas[i] == matricula){
            esta = true;
            pos = i;
         }
      }
      return pos;
   }

public:
   Tunel(double km){
      distancia_km = km;
      for (int i = 0; i < MAX_NUM_VEHICULOS; i++){
         entradas[i] = salidas[i] = INSTANTE_NULO;
         matriculas[i] = "";
      }
   }
   
   int TotalEntradas(){
      return total_entradas;
   }

   string getMatricula(int posicion){
      return matriculas[posicion];
   }

   void Entra(string matricula, int hora, int minuto, int segundo){
      if (total_entradas < MAX_NUM_VEHICULOS){
         int pos = estaMatricula(matricula);
         Instante tiempo(hora, minuto, segundo);
         if (pos != -1){
            entradas[pos] = tiempo.SegundosTotales();
         } else{
            matriculas[total_entradas] = matricula;
            entradas[total_entradas] = tiempo.SegundosTotales();
            total_entradas++;
         }
      }
   }

   void Sale(string matricula, int hora, int minuto, int segundo){
      int pos = estaMatricula(matricula);
      Instante tiempo(hora,minuto,segundo);
      if (pos != -1)
         salidas[pos] = tiempo.SegundosTotales();
   }   

   double Velocidad(string matricula){
      double velocidad = 0.0;
      int posicion = estaMatricula(matricula);
      int tiempo = abs(salidas[posicion]-entradas[posicion]);
      Instante tiempo_transcurrido(tiempo);
      velocidad = (distancia_km * 1.0) / tiempo_transcurrido.HorasTotalesDecimal();
      return velocidad;
   }

   bool haSalido (int pos){
      return salidas[pos] != -1;
   }

};


int main(){
   const char FIN_ENTRADA = '#';
   const char ENTRADA = 'E';
   const char SALIDA  = 'S';
   char acceso;
   bool error_lectura;

   string matricula;
   double long_tunel;
   int hora, min, seg;
  
   cin >> long_tunel;
   
   
   FormateadorDoubles formateador("", "km/h",1);
   Tunel tunel(long_tunel);

   cin >> acceso;
   error_lectura = false;
   
   while (acceso != FIN_ENTRADA && !error_lectura){
      cin >> matricula;
      cin >> hora >> min >> seg;
      
      if (acceso == ENTRADA)
         tunel.Entra(matricula, hora,min,seg);
      else if (acceso == SALIDA)       
         tunel.Sale(matricula,hora,min,seg);
      else
         error_lectura = true;
      
      cin >> acceso;
   }
   
   //-------------------------------------------------------------  
   
   if (error_lectura)
      cout << "\nSe produjo un error en la lectura. ";
   else{
      int total_entradas = tunel.TotalEntradas();
      
      for (int i = 0; i < total_entradas; i++){
         cout << "\nMatricula:\t" << tunel.getMatricula(i)
              << "\nVelocidad:\t";
         
         if (tunel.haSalido(i)){
            cout << formateador.GetCadena(tunel.Velocidad(tunel.getMatricula(i))) << endl;
         } else
         {
            cout << "No ha salido" << endl;
         }
         
      }
   }

   cout << endl;
}

// Entrada:
/*
3.4
E 4733MTI 0 0 13
E 5232LTL 0 1 19
S 4733MTI 0 1 36
E 3330PRB 0 2 40
S 5232LTL 0 3 25
#
*/

// Salida:
/*
Matr�cula:      4733MTI
Velocidad:      147.5 km/h

Matr�cula:      5232LTL
Velocidad:      97.1 km/h

Matr�cula:      3330PRB
Velocidad:      No ha salido
*/


//////////////////////////////////////////////////////////////////
   
// Entrada:
/*
   3.4
E 4733MTI 0 0 13
E 1976KEX 0 0 34
E 7717UQS 0 0 47
E 4744SEU 0 0 56
E 5232LTL 0 1 19
S 4733MTI 0 1 36
E 6188MOH 0 1 36
E 6603JHQ 0 2 4
E 6898DVW 0 2 17
E 3330PRB 0 2 40
S 1976KEX 0 2 53
E 1758HRV 0 2 56
E 8210YVI 0 3 9
S 5232LTL 0 3 25
S 6603JHQ 0 3 25
S 7717UQS 0 3 29
S 6188MOH 0 3 29
E 9265JJA 0 3 35
S 4744SEU 0 3 40
E 4864DUN 0 3 49
S 3330PRB 0 3 51
E 1071VVF 0 3 54
S 1758HRV 0 4 30
E 5917FBY 0 4 43
   */
   
   // Salida:
   /*
   Matr�cula:	4733MTI
Velocidad:	147.5 km/h

Matr�cula:	1976KEX
Velocidad:	88.1 km/h

Matr�cula:	7717UQS
Velocidad:	75.6 km/h

Matr�cula:	4744SEU
Velocidad:	74.6 km/h

Matr�cula:	5232LTL
Velocidad:	97.1 km/h

Matr�cula:	6188MOH
Velocidad:	108.3 km/h

Matr�cula:	6603JHQ
Velocidad:	151.1 km/h

Matr�cula:	6898DVW
Velocidad:	No ha salido

Matr�cula:	3330PRB
Velocidad:	172.4 km/h

Matr�cula:	1758HRV
Velocidad:	130.2 km/h

Matr�cula:	8210YVI
Velocidad:	No ha salido

Matr�cula:	9265JJA
Velocidad:	No ha salido

Matr�cula:	4864DUN
Velocidad:	No ha salido

Matr�cula:	1071VVF
Velocidad:	No ha salido

Matr�cula:	5917FBY
Velocidad:	No ha salido
   */

