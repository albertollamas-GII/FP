/*
Fichero rima.cpp
*/
#include <iostream>

using namespace std;

class SecuenciaCaracteres{
private:
    static const int MAX = 100;
    char vector_privado[MAX];
    int total_utilizados;
public:
    SecuenciaCaracteres(){ total_utilizados = 0;}
    void Aniade(char nuevo){ vector_privado[total_utilizados] = nuevo; total_utilizados++;}
    char Elemento(int indice){ return vector_privado[indice];}
    int TotalUtilizados(){return total_utilizados;}
    int Capacidad(){return MAX;}
    
    /* CODIGO EXAMEN */
    bool RimaAsonante( SecuenciaCaracteres s2, int k){
        int vocal1 = TotalUtilizados();
        int vocal2 = s2.TotalUtilizados();
        int contador = k;
        bool asonante = true;
        
        while ( asonante && contador > 0){
            vocal1 = AnteriorVocal(vocal1);
            vocal2 = s2.AnteriorVocal(vocal2);
            
            if ( vocal1 < 0 || vocal2 < 0 || Elemento(vocal1) != s2.Elemento(vocal2) )
                asonante = false;
            else{
                vocal1--;
                vocal2--;
                contador--;
            }
        }
        
        return asonante;
    }
    
    int AnteriorVocal(int pos){
        int salida = pos;
        bool encontrado = false;
        
        while ( salida >= 0 && !encontrado )
            if ( Elemento(salida)=='a' || Elemento(salida)=='e' || Elemento(salida)=='i' || Elemento(salida)=='o' || Elemento(salida)=='u')
                encontrado = true;
            else
                salida--;
        
        return salida;
    }
    /* FIN */
};



int main (){
    SecuenciaCaracteres a;
    SecuenciaCaracteres b;
    
    int l1, l2;
    char c;
    cin >> l1;
    for (int i=0; i<l1; i++){
        cin >> c;
        a.Aniade(c);
    }
    
    cin >> l2;
    for (int i=0; i<l2; i++){
        cin >> c;
        b.Aniade(c);
    }
    
    int k;
    cin >> k;
    
    bool asonante = a.RimaAsonante(b,k);
    
    if ( asonante )
        cout << "\nLa rima es asonante\n";
    else
        cout << "\nLa rima no es asonante\n";
        
}
