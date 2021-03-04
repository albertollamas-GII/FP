/**
Implemente un programa que lea valores int desde teclado 
y que tenga en cuenta u ́nicamente los valores 0 y 1 (representan valores de bits). 
El programa terminar ́a cuando se lea un valor negativo. Cada 8 valores de bits le ́ıdos, 
el programa calcular ́a el nu ́mero entero que representa y lo transformar ́a en el car ́acter 
(char) correspondiente. El primer bit le ́ıdo es el m ́as significativo. Si el car ́acter corresponde 
a una letra -mayu ́scula o minu ́scula- lo mostrar ́a por pantalla. Finalmente, el programa debe 
mostrar el porcentaje de letras y otros s ́ımbolos le ́ıdos.

Si no es posible completar el u ́ltimo bloque con 8 bits, no se considerar ́an los nu ́meros le ́ıdos.
*/

#include <iostream>
#include <cmath>

using namespace std;

// 4
/**
 * Funciones TablaRectangular => Constructores, filas y columnas utilizadas, elemento, modifica(f,c,valor)
 * */
class FlujoMensajes{
    private:
        TablaRectangular actividad;
        int num_usuarios;
    public:

        //Calcula la actividad de un usuario i
        int Actividad(int i){
            int salida = 0;
            for (int j = 0; j < num_usuarios; j++){
                if (j != i)
                    salida += actividad.Elemento(i, j);
            }

            return salida;
        }

        int Popularidad(int i){
            int popu = 0;

            for (int j = 0; j < num_usuarios; j++){
                if (i != j)
                    popu += actividad.Elemento(j,i);
            }

            return popu;
        }

        TablaRectangular Resumen(){
            const int UTIL = 2;
            TablaRectangular resumen (2, 2);

            for (int i = 0; i < resumen.FilasUtilizadas(); i++){
                for (int j = 0; j < resumen.ColumnasUtilizadas(); j++){
                    int actividad = Actividad(i);
                }
            }

            return resumen;
        }

        int MasPopular(){

        }

};

