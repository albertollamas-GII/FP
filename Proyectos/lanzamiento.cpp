// Alberto Llamas Gonz�lez

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	//Declaracion de variables
	const double GTERRESTRE=9.80665;
	const double PI=3.14159265358979323846;
	double posicionX, posicionY, velocidad_lanzamiento, angulo_elevacion;
	double altura_maxima, tiempo_vuelo , alcance, radianes_elevacion, radianes_rotacion,
			punto_impactoX, punto_impactoY;
	double localizacionX, localizacionY, d0, d1, impacto;
	double rotacion;
	
	//Entrada de datos
	cout << "\nIntroduzca dos valores con la posicion del canion: ";
	cin >> posicionX >> posicionY;
	
	cout << "\nIntroduzca la velocidad de lanzamiento (m/s): ";
	cin >> velocidad_lanzamiento;
	
	//Comprobamos que la velocidad es positiva
	bool es_velocidad=velocidad_lanzamiento > 0;
	
	if (es_velocidad){
		cout << "\nIntroduzca el angulo de elevacion en grados (0-90): ";
		cin >> angulo_elevacion;
		
		//Comprobamos que el angulo esta dentro del rango (0,90)
		bool es_angulo = angulo_elevacion > 0 && angulo_elevacion < 90;
		
		if (es_angulo){
			cout << "\nIntroduzca rotacion: ";
			cin >> rotacion;
			
			bool es_rotacion = rotacion <= 180 && rotacion >= -180;
			
			//Comprobamos que esta dentro de dicho rango [-180,180]
			if (!es_rotacion){
				rotacion = abs(rotacion) % 180;
				cout << "\nAngulo de rotacion rectificado: " << rotacion << endl;
			}
			
			//Calculo de lo pedido en el enunciado
			
			radianes_elevacion=angulo_elevacion * PI / 180;													//Transformamos los grados a radianes
			radianes_rotacion=rotacion*PI / 180;												
			
			tiempo_vuelo=2*(velocidad_lanzamiento*sin(radianes_elevacion))/GTERRESTRE;						//Calculo del tiempo de vuelo
			
			altura_maxima=pow(velocidad_lanzamiento*sin(radianes_elevacion), 2) / (2*GTERRESTRE);			//Calculo de la altura maxima
			
			alcance=pow(velocidad_lanzamiento,2)*sin(2*radianes_elevacion)/GTERRESTRE;						//Calculo del alcance
			
			punto_impactoX= posicionX+alcance*sin(radianes_rotacion);										//Calculo del punto de impacto
			punto_impactoY=posicionY+alcance*cos(radianes_rotacion);
			
			//Salida de resultados
			cout << "\n--------Resultado del disparo--------" << endl;			
			cout << "\nTiempo de vuelo: " << tiempo_vuelo << endl;		
			cout << "\nAltura maxima: " << altura_maxima << endl;		
			cout << "\nAlcance: " << alcance << endl;			
			cout << "\nImpacto: " << punto_impactoX << " , " << punto_impactoY<< endl;
			
			cout << "\n--------Comprobacion de objetivo--------" << endl;									//Entrada de datos del nuevo apartado
			
			cout << "\nIntroduzca localizacion del objetivo: ";
			cin >> localizacionX >> localizacionY ;
			
			cout << "\nIntroduzca distancias de impacto: ";
			cin >> d0 >> d1;
			
			//Comprobamos que se ha introducido primero la menor distancia y sino realizamos un intercambio
			if (d0 >= 0 && d1 >= 0){
				if (d1 < d0){
					double intercambio=d1;
					d1=d0;
					d0=intercambio;
				}
				
				impacto=sqrt(pow(punto_impactoX-localizacionX,2)+pow(punto_impactoY-localizacionY,2));		//Calculo del exito del disparo
				
				//Mediante booleanos vemos el tipo de impacto
				bool impacto_directo=impacto < d0;
				bool impacto_parcial=impacto > d0 && impacto < d1;
				
				cout << "\nDistancia al objetivo: " << impacto;
				
				if (impacto_directo)
					cout << " -> impacto directo. " << endl;
				else if (impacto_parcial)
					cout << " -> impacto parcial. " << endl;
				else
					cout << " -> no hay impacto. " << endl;
					
			} else
				cout << "\nError: distancias de impacto deben ser no negativas " << endl;
		} else 
			cout << "\nError: elevacion debe estar entre 0 y 90 " << endl;
	} else 
		cout << "\nError: Vinicial debe ser positiva " << endl;
	
	return 0; 
	
}
