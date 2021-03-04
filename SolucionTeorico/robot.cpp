/*
Fichero robot.cpp
*/
#include <iostream>

using namespace std;

int main (){
    const int MAX = 1000;
    int pos = 0;
    int veces_posicion[100] = {0};
    char ord[MAX];
    int numero_ordenes = 0;
    
    do{
        cin >> numero_ordenes;
    }while (numero_ordenes <= 0);
    
    for (int i=0; i<numero_ordenes; i++){
        do{
            cin >> ord[i];
        }while ( ord[i]!='I' && ord[i]!='D' );
    }
    
    do{
        cin >> pos;
    }while (pos <= 0 || pos > 100);
    
    /* CODIGO EXAMEN */
    
    bool correcto = true;
    int numero_ordenes_realizadas = 0;
    veces_posicion[pos-1]++;
    
    while ( correcto && numero_ordenes_realizadas < numero_ordenes ){
        if ( ord[numero_ordenes_realizadas] == 'D' )
            pos++;
        else
            pos--;

        correcto = pos > 0 && pos <= 100;
        
        if ( correcto ){
            veces_posicion[pos-1]++;
            numero_ordenes_realizadas++;
        }
    }
    
    if ( correcto ){
        cout << "\nSerie de ordenes: correcta\n";
        for (int i=0; i<100; i++)
            if ( veces_posicion[i] != 0 )
                cout << "(" << i+1 << "," << veces_posicion[i] << "), ";
        cout << "\n";
    }
    else{
        cout << "\nSerie de ordenes: incorrecta\n";
        cout << "Se ejecutaron " << numero_ordenes_realizadas << " ordenes\n";
    }
    
    /* FIN */
        
}
