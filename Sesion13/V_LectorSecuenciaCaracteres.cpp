#include <iostream>
#include <string>
#include "V_SecuenciaCaracteres.cpp"
using namespace std;
/*

Ejemplo de uso:
   SecuenciaCaracteres sec1, sec2;
   LectorSecuencias lector;
   
   lector.SetTerminador('#');
   lector.SetTope(5);

   sec1 = lector.Lee(); 
   sec2 = lector.Lee();
   
   lector.SetTope(1);
   ......
*/
class LectorSecuenciaCaracteres{
private:
   char terminador;
   int tope;
   int capacidad_maxima;

   bool FlujoAbierto(){
      return !cin.fail();
   }
   
public:
   LectorSecuenciaCaracteres(){
      ResetRestricciones();
   }
   
   void SetTerminador (char terminador_entrada){
      terminador = terminador_entrada;
   }
   
   void SetTope(int num_valores_a_leer){
      if (0 < num_valores_a_leer && num_valores_a_leer <= capacidad_maxima)
         tope = num_valores_a_leer;
   }
   
   void ResetRestricciones(){
      SecuenciaCaracteres cualquiera;
      
      capacidad_maxima = cualquiera.Capacidad();
      tope = capacidad_maxima;
      terminador = '\n';
   }
   
   SecuenciaCaracteres Lee(){   
      SecuenciaCaracteres a_leer;
      char caracter;      
      bool parar_lectura;
      bool es_terminador;
      int total_leidos = 0;
      
      do{            
         if (FlujoAbierto()){            
            caracter = cin.get();  
            total_leidos++;
            es_terminador = caracter == terminador;
                                  
            if (!es_terminador) 
               a_leer.Aniade(caracter); 
            
            parar_lectura = es_terminador || total_leidos == tope;                           
         }
      }while (!parar_lectura);
      
      return a_leer;
   }
};

int main(){

   SecuenciaCaracteres secuencia1, secuencia2;
   LectorSecuenciaCaracteres lector;

   lector.SetTerminador('#');
   lector.SetTope(8);

   secuencia1 = lector.Lee();
   secuencia2 = lector.Lee();

}

