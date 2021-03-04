Ejercicio1.txt

int ValorAbsoluto(int entero){
    if (entero < 0)
        entero = -entero;
    else
        return entero;
}
// Error ya que solo devolveria algun valor / haría un return si entero fuese > 0. Para arreglarlo podemos hacer lo siguiente
int ValorAbsoluto(int entero){
    if (entero < 0)
        entero = -entero;
    return entero;
}


bool EsPositivo(int valor){
    if (valor > 0)
        return true;
}
//No devolveria nunca false la funcion EsPositivo. Para ello basta con modificarla de la siguiente manera
bool EsPositivo(int valor){
    return (valor > 0);
}


long ParteEntera(double real){
    int parte_entera;
    parte_entera = trunc(real);
    return parte_entera;
}
//Devolveria un int en vez de un long por lo que si se introduce un valor tipo long , no entraria en el int por lo que lo truncaría
// Las funciones deben devolver un valor del tipo que son (excepto las void que no devuelven nada)

long ParteEntera(double real){
    long parte_entera;
    parte_entera = trunc(real);
    return parte_entera;
}