//Alberto Llamas Gonzalez

#include <iostream>
using namespace std;

class Cuadrado{
private:
   double abcisa;
   double ordenada;
   double lado;

public:
   Cuadrado(double abcisa, double ordenada, double lado){
      if (lado > 0){
         this->abcisa = abcisa;
         this->ordenada = ordenada;
         this->lado = lado;
      }else {
         this->abcisa = -1;
         this->ordenada = -1;
         this->lado = -1;
      }
   }
   void SetAbcisa(double abcisa){
         this->abcisa = abcisa;
   }
   void SetOrdenada(double ordenada){
      this->ordenada = ordenada;
   }
   void SetLado(double lado){
      if (lado > 0)
         this->lado = lado;
      else
         this->lado = -1;
   }
   void SetCoordenada(double abcisa, double ordenada){
      this->abcisa = abcisa;
      this->ordenada = ordenada;
   }
   double GetAbcisa(){
      return abcisa;
   }
   double GetOrdenada(){
      return ordenada;
   }
   double GetLado(){
      return lado;
   }
   //No hay que añadirlo como dato miembro ya que se usaran fuera de la clase
   double area(){
      double area = this->lado * this->lado;
      return area;
   }
   //No debemos añadirlo como dato miembro ya que se usaran en el main
   double perimetro(){
      double perimetro = 4 * this->lado;
      return perimetro;
   }
};

int main(){
   const string MSJ_COORDENADAS = "\nCoordenadas: ";
   const string MSJ_LONGITUD = "\nLongitud: ";
   const string MSJ_AREA = "\nÁrea: ";
   const string MSJ_PERIMETRO = "\nPerímetro: ";
   double esquina_x, esquina_y, long_parcela;

   cout << "Introduzca los datos de dos cuadrados:"
        << "\nEn primer lugar las dos coordenadas de la esquina inferior izquierda"
        << "\nA continuación la longitud de su lado\n";

   // ----------------------------------------------------
   cin >> esquina_x;
   cin >> esquina_y;
   cin >> long_parcela;

   Cuadrado parcela(esquina_x,esquina_y,long_parcela);

   cin >> esquina_x;
   cin >> esquina_y;
   cin >> long_parcela;

   Cuadrado otra_parcela(esquina_x, esquina_y, long_parcela);

   // ----------------------------------------------------

   cout << MSJ_COORDENADAS << "(" << parcela.GetAbcisa() << "," << parcela.GetOrdenada() << ")"
        << MSJ_LONGITUD << parcela.GetLado()
        << MSJ_AREA << parcela.area()
        << MSJ_PERIMETRO << parcela.perimetro();

   cout << "\n";

   cout << MSJ_COORDENADAS << "(" << otra_parcela.GetAbcisa() << "," << otra_parcela.GetOrdenada() << ")"
        << MSJ_LONGITUD << otra_parcela.GetLado()
        << MSJ_AREA << otra_parcela.area()
        << MSJ_PERIMETRO << otra_parcela.perimetro();

   cout << "\n";
}

/*
3.4  5.7  2.9
-5.6 -4.1 1.8
*/
/*
Coordenadas: 3.4 , 5.7
Longitud: 2.9
Área: 8.41
Perímetro: 11.6

Coordenadas: -5.6 -4.1
Longitud: 1.8
Área: 3.24
Perímetro: 7.2 
*/
