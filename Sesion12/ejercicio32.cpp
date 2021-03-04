//Alberto Llamas Gonzalez

//Claramente ambas funciones podrian ser funciones globales

/**
 * Este metodo SI tendria sentido que fuese tanto un metodo publico o un metodo
 * privado ya que serviria para que un usuario desde el main quiera ver si una
 * letra es una vocal o no o para usarlo unicamente dentro de la clase.
 * */
bool EsVocal(int indice);

/**
 * Este metodo tendría sentido que fuese un metodo privado ya que nos podria servir
 * para ver si una letra de la secuencia es una vocal o no, pero si es un metodo publico,
 * el usuario puede introducir una letra que no se encuentre en la secuencia por lo que no 
 * devolveria nada logico
 * */

bool EsVocal(char letra);