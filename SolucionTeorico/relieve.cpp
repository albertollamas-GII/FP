/*
Fichero relieve.cpp
*/
#include <iostream>

using namespace std;

class Punto2D{
private:
    int posX, posY;
public:
    Punto2D(int x, int y){posX=x; posY=y;}
    Punto2D(){posX=0; posY=0;}
    int ObtenerPosX(){return posX;}
    int ObtenerPosY(){return posY;}
    double Distancia(Punto2D otro){
        int a=posX-otro.posX;
        int b=posY-otro.posY;
        if ( a < 0 )
            a = -a;
        if (b < 0 )
            b = -b;
        return a+b;
    }
};

class SecuenciaPuntos{
private:
    static const int MAX = 100;
    Punto2D lista[MAX];
    int utilizados;
public:
    SecuenciaPuntos(){ utilizados = 0;}
    void Aniade(Punto2D pto){ lista[utilizados] = pto; utilizados++;}
    Punto2D ObtenerPunto(int i){ return lista[i];}
    int Utilizados(){return utilizados;}
};

class Relieve{
    private:
        static const int MAX_LARGO = 100;
        static const int MAX_ANCHO = 100;
        int t[MAX_LARGO][MAX_ANCHO];
        int largo, ancho;
    public:
        Relieve (int la, int an){
            largo = la;
            ancho = an;
            for (int i=0; i<largo; i++)
                for (int j=0; j<ancho; j++)
                    t[i][j] = 0;
        }
        int ObtenerLargo(){
            return largo;
        }
        int ObtenerAncho(){
            return ancho;
        }
        int ObtenerAltura(int x, int y){
            return t[x][y];
        }
        void ModificarAltura(int x, int y, int alt){
            t[x][y] = alt;
        }
    
    /* CODIGO EXAMEN */
        bool EsPico(int x, int y){
            bool pico = false;
        
            if ( x > 0 && x < ancho-1 && y > 0 && y < largo-1)
                pico = t[x-1][y-1] < t[x][y] &&
                        t[x][y-1] < t[x][y] &&
                        t[x+1][y-1] < t[x][y] &&
                        t[x-1][y] < t[x][y] &&
                        t[x+1][y] < t[x][y] &&
                        t[x-1][y+1] < t[x][y] &&
                        t[x][y+1] < t[x][y] &&
                        t[x+1][y+1] < t[x][y];
            // o bien, usando ObtenerAltura
            return pico;
        }
        SecuenciaPuntos ObtenerPicos (){
            SecuenciaPuntos picos;
        
            for ( int i=0; i<largo; i++)
                for (int j=0; j<ancho; j++)
                    if ( EsPico(i,j) )
                        picos.Aniade( Punto2D(i,j) );
        
            return picos;
        }
        Relieve Fusion (Relieve otro){
            int nuevo_largo = ObtenerLargo();
            int nuevo_ancho = ObtenerAncho();
        
            if ( nuevo_largo > otro.ObtenerLargo() )
                nuevo_largo = otro.ObtenerLargo();
        
            if ( nuevo_ancho > otro.ObtenerAncho() )
                nuevo_ancho = otro.ObtenerAncho();
        
            Relieve fusion (nuevo_largo, nuevo_ancho);
        
            for (int i=0; i<nuevo_largo; i++)
                for (int j=0; j<nuevo_ancho; j++)
                    if ( ObtenerAltura(i,j) < otro.ObtenerAltura(i,j) )
                        fusion.ModificarAltura(i,j, otro.ObtenerAltura(i,j));
                    else
                        fusion.ModificarAltura(i,j, ObtenerAltura(i,j));
            
            return fusion;
        }
    /* FIN */
};



int main (){
    int a,b,c,d;
    int alt;
    cin >> a >> b;
    Relieve uno(a,b);
    for (int i=0; i<a; i++){
        for (int j=0; j<b; j++){
            cin >> alt;
            uno.ModificarAltura(i,j,alt);
        }
    }
    
    cin >> c >> d;
    Relieve otro(c,d);
     for (int i=0; i<c; i++){
         for (int j=0; j<d; j++){
             cin >> alt;
             otro.ModificarAltura(i,j,alt);
         }
     }
    
    /* CODIGO EXAMEN */
    
    SecuenciaPuntos picos = uno.ObtenerPicos();
    int cx;
    int cy;
    int calt;
    int maximo;
    Punto2D max;
    
    if ( picos.Utilizados() > 0 ){
        cx = picos.ObtenerPunto(0).ObtenerPosX();
        cy = picos.ObtenerPunto(0).ObtenerPosY();
        calt = uno.ObtenerAltura(cx,cy);
        maximo = calt;
        max = picos.ObtenerPunto(0);
    
        for (int i=1; i<picos.Utilizados(); i++){
            cx = picos.ObtenerPunto(i).ObtenerPosX();
            cy = picos.ObtenerPunto(i).ObtenerPosY();
            calt = uno.ObtenerAltura(cx,cy);
    
            if ( calt > maximo ){
                maximo = calt;
                max = picos.ObtenerPunto(i);
            }
        }
    
        cout << "\nEl pico maximo esta en: (" << max.ObtenerPosX() << ", " << max.ObtenerPosY() << ") con altura " << maximo << "\n";
    }
    else
        cout << "\nNo hay picos\n";
    
    int dist = 0;
    
    for (int i=0; i<picos.Utilizados()-1; i++)
        dist = dist + picos.ObtenerPunto(i).Distancia(picos.ObtenerPunto(i+1));
    
    cout << "\nLa distancia entre picos es: " << dist << "\n";
    
    Relieve fus = uno.Fusion(otro);
    SecuenciaPuntos picos_fusion = fus.ObtenerPicos();
    
    cout << "\nLos picos de la fusion estan en: \n";
    for (int i=0; i<picos_fusion.Utilizados(); i++){
        cout << picos_fusion.ObtenerPunto(i).ObtenerPosX() << " ";
        cout << picos_fusion.ObtenerPunto(i).ObtenerPosY();
        cout << "\n";
    }
    
    /* FIN */
}
