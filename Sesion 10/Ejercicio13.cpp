//Alberto Llamas Gonzalez

/*
    En este caso, el problema de EliminaUltimo, es que no modifica nada a la cadena que se le pasa 
    en el argumento de la funcion. Para que se modificase, deberíamos de pasar la cadena por referencia &cadena,

*/

void EliminaUltimo(string cadena){
    cadena.pop_back();
}

/*
    En esta funcion hay un error ya que redefine la variable valor por lo que tendríamos dos 
    variables del mismo tipo con el mismo nombre dandonos y error de compilacion
*/
void Imprime(double valor){
    double valor;
    cout << valor;
}

/*
    Claramente esta función void es erronea ya que un void no puede hacer return dentro de ella
*/
void Cuadrado (int entero){
    return entero*entero;
}
