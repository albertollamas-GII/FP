//Alberto Llamas Gonzalez
#include <iostream>
#include <random> // para la generación de números pseudoaleatorios
#include <chrono> // para la semilla

using namespace std;

class GeneradorAleatorioEnteros{
private:
    mt19937 generador_mersenne; // Mersenne twister
    uniform_int_distribution<int> distribucion_uniforme;
    long long Nanosec(){
        return chrono::high_resolution_clock::now().time_since_epoch().count();
    }
public:
    GeneradorAleatorioEnteros()
    : GeneradorAleatorioEnteros(0, 1){
    }

    GeneradorAleatorioEnteros(int min, int max){
        const int A_DESCARTAR = 70000;
        // ACM TOMS Volume 32 Issue 1, March 2006
        auto semilla = Nanosec();
        generador_mersenne.seed(semilla);
        generador_mersenne.discard(A_DESCARTAR);
        distribucion_uniforme =
            uniform_int_distribution<int>(min, max);
    }
    int Siguiente(){
        return distribucion_uniforme(generador_mersenne);
    }
};

int main(){
    
    GeneradorAleatorioEnteros num_valores_a_generar(1, 5), aleatorio_0_1;
    const int REPETICIONES = 4;
    
    for (int i = 0; i < REPETICIONES; i++){
        int numero_generado = num_valores_a_generar.Siguiente();
        cout << numero_generado <<"\t";
        for (int j = 0; j < numero_generado; j++){
            int numero_0_1 = aleatorio_0_1.Siguiente();
            cout << numero_0_1 << " ";
        }
        cout << endl;
    }
}