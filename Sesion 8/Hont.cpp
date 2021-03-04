#include <iostream>

using namespace std;

int main()
{
    const int TAM_MAX = 100;
    int numero_partidos;
    long long int votos[TAM_MAX];
    int escanos_partidos[TAM_MAX];
    long long int cociente_dhont[TAM_MAX];
    int partido;
    int max;
    int escanos;

    cout << "Introduce la cantidad de escaños que hay: ";
    cin >> escanos;
    cout << "Introduce la cantidad de partidos que hay: ";
    cin >> numero_partidos;

    for (int i = 0; i < numero_partidos; i++)
    {
        cout << "Introduce la cantidad de votos del partido " << i+1 << " : ";
        cin >> votos[i];
        cociente_dhont[i] = votos[i];
        escanos_partidos[i] = 0;
    }

    for (int g = 0; g < escanos; g++)
    {

        for (int k = 0; k < numero_partidos; k++)
        {

            if (k == 0)
            {
                max = cociente_dhont[0];
                partido = 0;
            }
            if (max < cociente_dhont[k])
            {
                max = cociente_dhont[k];
                partido = k;
            }
        }
        escanos_partidos[partido] = escanos_partidos[partido] + 1;
        cociente_dhont[partido] = votos[partido] * 1.0 / (escanos_partidos[partido] + 1.0);
    }

    for (int j = 0; j < numero_partidos; j++)
    {
        cout << "\nEl partido número " << j << " tiene " << escanos_partidos[j] << " escaños con " << votos[j] << " votos";
    }
}