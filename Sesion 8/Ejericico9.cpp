//Alberto Llamas Gonzalez
#include <iostream>

using namespace std;

int main() {

    const int TAM_MAX=100;
    int numero_escanos=0, num_partidos=0;
    int votos[TAM_MAX], escanos[TAM_MAX] = {0};
    double honts[TAM_MAX];
    int max, partido;

    cin >> numero_escanos;
    cin >> num_partidos;

    for (int i = 0; i < num_partidos; i++) {
        cin >> votos[i];
        honts[i] = votos[i];
    }

    for (int i = 0; i < numero_escanos; i++) {
        max = honts[0];
        partido = 0;

        for (int j = 0; j < num_partidos; j++) {
            if (max < honts[j]) {
                max = honts[j];
                partido = j;
            }
        }
        escanos[partido] = escanos[partido] + 1;
        honts[partido] = votos[partido] * 1.0 / (escanos[partido] + 1.0);
    }

    for (int i = 0; i < num_partidos; i++)
        cout << escanos[i] << " ";
    
    cout << "\n\n";
}
