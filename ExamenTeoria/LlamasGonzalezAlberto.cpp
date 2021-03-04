/*
    32081180K
    Llamas González, Alberto
*/

//*****************************************************************************

#include <iostream>

using namespace std;

//*****************************************************************************
//Ejercicio1
//variara bastante con la primera entrega porque entendi mal el ejercicio
class SecuenciaCaracteres{
    private:
        static const int TAMANIO = 5e6;
        char v[TAMANIO];
        int utilizados;

         //metodo privado que devuelve el numero de repeticiones daod un caracter
        int Frecuencia(char a){
            int repeticiones = 0;
            for (int i = 0; i < TotalUtilizados(); i++){
                if (Elemento(i) == a)
                    repeticiones++;
            }
            return repeticiones;
        }

    public:

        //Suponemos la implementación de los métodos dados
        //a) 
        //De ambito publico ya que considero que puede ser util 
        //en el caso de la implementacion en un main o el uso en otra clase
        SecuenciaCaracteres SubSecuencia(int inicio, int final){
            SecuenciaCaracteres subsecuencia;
            //Comprobamos que los valores de inicio
            if (inicio > 0 && final < utilizados){
                //Aniadimos desde inicio hasta final a la subsecuencia los 
                //valores dados
                for (int i = inicio; i < final; i++){
                    subsecuencia.Aniade(Elemento(i));
                }
            }
            // Si inicio < 0 ó final > utlizados Devolvemos secuencia vacia
                return subsecuencia;
        }

        bool EsPalisimetrica(){
            bool espal = true;
            SecuenciaCaracteres sub1, sub2;
            int mitad1 = utilizados/2 - 1, mitad2;
            
            if(utilizados%2 == 0){
               mitad2 = mitad1 + 1;
            else
               mitad2 = mitad1 + 2;

            sub1 = Subsecuencia(0, mitad1);
            sub2 = Subsecuencia(mitad2, utilizados-1);

            for(int i=0; i<sub1.Utilizados() && espal; i++){
               if(sub2.PrimeraOcurrencia(sub1.Elemento(i)) == -1)      
                     espal = false;
               else if(sub1.Frecuencia(Elemento(i)) != sub2.Frecuencia(Elemento(i)))
                     espal = false;
            }

            for(int i=0; i<sub2.Utilizados() && espal; i++){
               if(sub1.PrimeraOcurrencia(sub2.Elemento(i)) == -1)      
                     espal = false;
            }

            return espal;
}


        //b)
        /*
            Comprobación Metodo EsPalisimetrica
                albertollamas
                    Calculamos primero las dos mitades
                        a l b e r t o
                    En el bucle while comprobamos desde la mitad hasta 0 y
                    final respectivamente si son iguales las frecuencias
                    a l b e r t o
                                o l l a m a s
                 Priemro comprobamos que todos los elementos de la primera mitad estan e
                 la segunda si no lo encontramos es falso, si lo encuentra comprobamos frecuencia
                 
                    
        */

};



//*****************************************************************************
//Ejercicio2
 
 class Tablero{
     private:
        static const int MAX = 1e3;
        long t[MAX][MAX];
        int dimension;
        /*
            La funcion de este metodo es sumar las columnas de el tablero
            Para ello lo recorre y añade la suma al objeto de la clase
            SecuenciaEnterosLong sumaColumnas.
        */
        SecuenciaEnterosLong SumaColumnas(){
            SecuenciaEnterosLong sumaColumnas;

            for (int j = 0; j < dimension; j++){
                long suma = 0;
                for (int i = 0; i < dimension; i++){
                    suma += Elemento(i,j);
                } 
                sumaColumnas.Aniade(suma);
            }
            return sumaColumnas;
        }

    public:
        /*
            calculamos la diagonal inversa
            Recorremos el tablero y mediante una varible k 
            que actua como un contador vamos comparando la columna 
            con la dimension - k. 
                Veamos el ejemplo propuesto

                9 8 7
                2 1 6
                3 4 2

                Recorremos y comprobamos la condicion:
                    j = 0 != 3-1
                    j = 1 != 3-1
                    j = 2 == 3-1 -> aniadimos el elemento
                    a el objeto de SecuenciaEnterosLong
        */
        SecuenciaEnterosLong DiagonalInversa(){
            SecuenciaEnterosLong inversa; 
            int k = 1;
            for (int i = 0; i < dimension; i++){
                for (int j = 0; j < dimension; j++){
                    if (j == (dimension - k)){
                        k++;
                        inversa.Aniade(Elemento(i,j));
                    }
                }
            }
            return inversa;
        }

        bool Heterogeneo(){
            SecuenciaEnterosLong sumaColumnas;
            sumaColumnas = SumaColumnas();

            bool heterogeneo = true;
            long anterior, actual;
            anterior = sumaColumnas.Elemento(0);
            for (int i = 1; i < sumaColumnas.Utilizados() && heterogeneo; i++){
                actual = sumaColumnas.Elemento(i);
                if (anterior == actual){
                    heterogeneo = false;
                }
                anterior = actual;
            }

            return heterogeneo;
        }

        bool HeterogeneoCompleto(){
            SecuenciaEnterosLong sumaColumnas;
            sumaColumnas = SumaColumnas();

            sumaColumnas.OrdenaCreciente();
            bool es_heterogeneo = Heterogeneo();
            bool es_heterogeneoCompleto = true;

            if (es_heterogeneo){
                long anterior = sumaColumnas.Elemento(0);
                for (int i = 1; i < sumaColumnas.Utilizados() && es_heterogeneoCompleto; i++){
                    if (sumaColumnas.Elemento(i) != (anterior + 1)){
                        es_heterogeneoCompleto = false;
                    }

                    anterior = sumaColumnas.Elemento(i);
                }
            } else{
                es_heterogeneoCompleto = false;
            }

            return es_heterogeneoCompleto;
        }

        /*
            Construyamos el tablero con DNI: 32081180K (K==3)
                3 2 0
                8 1 1
                8 0 3

                Explicaré ahora como funciona heterogeneo completo que implica
                la explicacion de heterogeneo:
                    En primer lugar declaramos un objeto de la clase 
                    SecuenciaEnterosLong y calculamos su suma con el metodo
                    privado SumaColumnas(). Este método ya ha sido explicado 
                    anteriormente. 
                    Después, ordenamos la suma de las columnas
                    con el método proporcionado OrdenaCreciente(). 
                    Cuando ya tenemos la suma ordenada comprobamos que 
                    el tablero es heterogeneo y lo almacenamos en un booleano
                    Si es heterogeneo, comprobamos que sea heterogeneo completo
                    Sino, se devuelve false. 
                    Para comprobar si es heterogeneo, lo que hacemos es
                    recorrer sumaColumnas desde 1 hasta utilizados y guardamos
                    el valor del primer elemento en una variable auxiliar
                    anterior. Dentro del bucle que recorre el objeto,
                    comprobamos que el elemento actual es decir que la suma
                    si+1 (imaginemos que es subindice i+1) = si + 1. 
                    Es decir, el siguiente es igual al anterior + 1.
                    Si no es igual, nos salimos del bucle y devuelve false
                    y si cumple la condicion, devuelve true.

        */
 };