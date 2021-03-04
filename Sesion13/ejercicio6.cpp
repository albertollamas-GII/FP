#include <cmath>
#include <iostream>
using namespace std;


class Instante{
private:            
   static const int  SEG_1_MIN = 60,
                     MIN_1_HORA = 60,
                     HOR_1_DIA = 24;  
   
   int hor = -1;
   int min = -1;
   int seg = -1;
   
   bool EsCorrectoSeg(int segundo){
      return 0 <= segundo && segundo < SEG_1_MIN;
   }
   bool EsCorrectoMin(int minuto){
      return 0 <= minuto && minuto < MIN_1_HORA;
   }
   bool EsCorrectoHor(int hora){
      return 0 <= hora  && hora < HOR_1_DIA;
   }
   bool EsCorrecto (int hora, int minuto, int segundo){
      return  EsCorrectoHor(hora) && 
              EsCorrectoMin(minuto) && 
              EsCorrectoSeg(segundo);
   }

public:

   Instante(){      
   }
   
   Instante(int hora, int minuto, int segundo){
      SetHoraMinutoSegundo(hora,  minuto,  segundo);
   }
   
   // Prec: los segundos son correctos
   Instante(int segundos_totales){
      SetSegundosTotales(segundos_totales);
   }

   int Hora(){
      return hor;
   }

   int Minuto(){
      return min;
   }

   int Segundo(){
      return seg;
   }

   void SetHoraMinutoSegundo(int hora, int minuto, int segundo){
      if (EsCorrecto(hora, minuto, segundo)){
         hor = hora;
         min = minuto;
         seg = segundo;
      }
   }

   void SetSegundosTotales(int segundos_totales){
      int minutos_enteros;
      const int SEG_1_DIA = SEG_1_MIN * MIN_1_HORA * HOR_1_DIA;
                                    
      if (segundos_totales < SEG_1_DIA){
         seg = segundos_totales % SEG_1_MIN;
         minutos_enteros  = segundos_totales / SEG_1_MIN;
         min  = minutos_enteros % MIN_1_HORA;
         hor  = minutos_enteros / MIN_1_HORA;
      }
   }

   void SumaleSegundos(int segundos_a_aniadir){
      if (segundos_a_aniadir > 0)
         SetSegundosTotales(
            SegundosTotales() 
            + 
            segundos_a_aniadir);       
   }
   
   void RestaleSegundos(int segundos_a_quitar){
      if (segundos_a_quitar > 0)
         SetSegundosTotales(
            SegundosTotales() 
            -
            segundos_a_quitar);
   }

   bool EsNulo(){
      return !EsCorrecto(hor, min, seg);  
   }

   int SegundosTotales(){
      return seg  +  SEG_1_MIN*(hor * MIN_1_HORA + min);
   }
   
   int MinutosTotales(){
      return trunc(MinutosTotalesDecimal());
   }

   double MinutosTotalesDecimal(){
      return 1.0 * SegundosTotales() / SEG_1_MIN;
   }

   double HorasTotalesDecimal(){
      return 1.0 * MinutosTotalesDecimal() / MIN_1_HORA;
   }

   string ToString(){
      return to_string(hor) + "h, " +
             to_string(min) + "\', " +
             to_string(seg) + "\'\'";
   }

   ///////////////////////////////////////////////////////////////////////
   // M�todos NUEVOS
   ///////////////////////////////////////////////////////////////////////


   void Sumale(Instante otro_instante){
      SumaleSegundos(otro_instante.SegundosTotales());
   }
   
   void Restale(Instante otro_instante){
      RestaleSegundos(otro_instante.SegundosTotales());
   }
   
   Instante Suma(Instante otro_instante){
      Instante suma;
      suma.SetSegundosTotales(SegundosTotales());
      suma.SumaleSegundos(otro_instante.SegundosTotales());
      
      return suma;
   }

   Instante DiferenciaCon(Instante otro_instante){
      int segundos_iniciales, segundos_finales, segundos_diferencia;

      segundos_iniciales = SegundosTotales();
      segundos_finales   = otro_instante.SegundosTotales();
      segundos_diferencia = abs(segundos_finales - segundos_iniciales);

      Instante diferencia_con;

      diferencia_con.SetSegundosTotales(segundos_diferencia);

      return diferencia_con;
   }  
};

