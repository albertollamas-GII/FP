//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// Instante en un d�a -> hora, minuto, segundo (desde las 0h)

#include <cmath>
#include <string>
using namespace std;

/*
class Instante
   Instante(int hora_instante, int minuto_instante, int segundo_instante)
   Instante(int segundos_totales)
   Instante()
   int Hora()
   int Minuto()
   int Segundo(){
   void SetHoraMinutoSegundo(int hora_instante,
                             int minuto_instante,
                             int segundo_instante)
   void SetSegundosTotales(int segundos_totales)
   void SumaleSegundos(int segundos_a_aniadir)
   void RestaleSegundos(int segundos_a_quitar)
   bool EsNulo()
   int SegundosTotales()   
   int MinutosTotales()
   double MinutosTotalesDecimal()
   double HorasTotalesDecimal()
   string ToString()
*/


class Instante{
private:    
   /*
   MUY IMPORTANTE:
      NO INCLUIMOS COMO DATO MIEMBRO NADA QUE SE PUEDA OBTENER A PARTIR
      DE LOS OTROS DATOS MIEMBRO,COMO POR EJEMPLO SEGUNDOS_TOTALES
      LO QUE HAREMOS SER� PROPORCIONAR UN M�TODO QUE CALCULE SEGUNDOS_TOTALES
   */
   
   /*
   Sobre las ctes:
   
      Hemos decidido que las ctes SEG_1_MIN, MIN_1_HORA y HOR_1_DIA
      sean private ya que hemos supuesto que no se necesitan fuera de la clase.
      Pero podr�a darse el caso de que s� se necesitasen.
      Por ejemplo, si desde el main queremos hacer un filtro de entrada de datos para los
      minutos, por ejemplo, necesitar�amos saber el m�ximo (60)
      En este caso, podemos resolverlo de dos formas:
      
      a) Poner dichas ctes como ctes globales 
      
      b) Proporcionar m�todos Get a la clase Instante 
         para que devuelva los valores de dichas ctes.
         El problema de esta opci�n es que no podr�amos
         dimensionar un vector, por ejemplo, con estos valores
         ya que el valor devuelto por el m�todo Get no ser�a un const.
         
      c) Tambi�n se pueden poner las constantes SEG_1_MIN, MIN_1_HORA
         y HOR_1_DIA como datos miembros p�blicos: Ser�a la �nica excepci�n a la norma
         de usar siempre datos miembros privados.
         De esta forma, desde el main, si tenemos 
            Instante un_instante;
         podemos acceder a dichos datos miembros. 
         Se puede hacer de dos formas (pero siempre declar�ndolas como "static const"):
         
         i)  objeto.dato_miembro
            
             En nuestro ejemplo ser�a:
            
             instante.SEG_1_MIN
            
         ii) clase::dato_miembro
            
             En nuestro ejemplo ser�a:
   
             Instante::SEG_1_MIN
   */
         
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
   // Incluimos un constructor sin par�metros para poder crear f�cilmente vectores de objetos.
   // Al construir un objeto Instante llamando al constructor sin par�metros
   // �ste se quedar� como un "zombie". Lo identificaremos poniendo sus datos miembro
   // a -1 y proporcionando el m�todo EsNulo()
   //    Instante un_instante;  <-  -1, -1, -1
   //    bool es_nulo = un_instante.EsNulo();   <- true
   Instante(){      
   }
   
   // Prec: las horas, minutos y segundos son correctos
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
};


