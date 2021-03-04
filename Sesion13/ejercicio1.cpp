//Alberto Llamas Gonzalez
#include <iostream>
#include <string>
using namespace std;

struct FrecuenciaCaracter
{
    char caracter;
    int frecuencia;
};

class SecuenciaCaracteres
{
private:
    static const int TAMANIO = 2e6; // 2e6 es un real (dos millones)
                                    // -> casting automático a int
    char v[TAMANIO];
    int utilizados;

    void IntercambiaComponentesDirectamente(int pos_izda, int pos_dcha)
    {
        char intercambia;

        intercambia = v[pos_izda];
        v[pos_izda] = v[pos_dcha];
        v[pos_dcha] = intercambia;
    }

    bool EsCorrectaPos(int indice)
    {
        return 0 <= indice && indice < utilizados;
    }

public:
    SecuenciaCaracteres()
        : utilizados(0)
    {
    }

    int Utilizados()
    {
        return utilizados;
    }

    int Capacidad()
    {
        return TAMANIO;
    }

    void EliminaTodos()
    {
        utilizados = 0;
    }

    void Aniade(char nuevo)
    {
        if (utilizados < TAMANIO)
        {
            v[utilizados] = nuevo;
            utilizados++;
        }
    }

    void Modifica(int posicion, char nuevo)
    {
        if (EsCorrectaPos(posicion))
            v[posicion] = nuevo;
    }

    char Elemento(int indice)
    {
        return v[indice];
    }

    string ToString()
    {
        // Si el número de caracteres en memoria es muy grande,
        // es mucho más eficiente reservar memoria previamente
        // y usar push_back

        string cadena;

        cadena.reserve(utilizados);

        for (int i = 0; i < utilizados; i++)
            cadena.push_back(v[i]);
        //cadena = cadena + v[i]  <- Evitarlo. Muy ineficiente para tamaños grandes;

        return cadena;
    }

    int PrimeraOcurrenciaEntre(int pos_izda, int pos_dcha, char buscado)
    {
        int i = pos_izda;
        bool encontrado = false;

        while (i <= pos_dcha && !encontrado)
            if (v[i] == buscado)
                encontrado = true;
            else
                i++;

        if (encontrado)
            return i;
        else
            return -1;
    }

    int PrimeraOcurrencia(char buscado)
    {
        return PrimeraOcurrenciaEntre(0, utilizados - 1, buscado);
    }

    /////////////////////////////////////////////////////////////
    // Búsquedas

    // Precond: 0 <= izda <= dcha < utilizados
    int PosMinimoEntre(int izda, int dcha)
    {
        int pos_minimo = -1;
        char minimo;

        minimo = v[izda];
        pos_minimo = izda;

        for (int i = izda + 1; i <= dcha; i++)
            if (v[i] < minimo)
            {
                minimo = v[i];
                pos_minimo = i;
            }

        return pos_minimo;
    }

    int PosMinimo()
    {
        return PosMinimoEntre(0, utilizados - 1);
    }

    int BusquedaBinaria(char buscado)
    {
        int izda, dcha, centro;
        bool encontrado = false;

        izda = 0;
        dcha = utilizados - 1;
        centro = (izda + dcha) / 2;

        while (izda <= dcha && !encontrado)
        {
            if (v[centro] == buscado)
                encontrado = true;
            else if (buscado < v[centro])
                dcha = centro - 1;
            else
                izda = centro + 1;

            centro = (izda + dcha) / 2;
        }

        if (encontrado)
            return centro;
        else
            return -1;
    }

    /////////////////////////////////////////////////////////////
    // Recorridos que modifican las componentes

    // Inserta un valor en la posición especificada
    void Inserta(int pos_insercion, char valor_nuevo)
    {
        if (utilizados < TAMANIO && pos_insercion >= 0 && pos_insercion <= utilizados)
        {

            for (int i = utilizados; i > pos_insercion; i--)
                v[i] = v[i - 1];

            v[pos_insercion] = valor_nuevo;
            utilizados++;
        }
    }

    void Elimina(int posicion)
    {
 
        if (posicion >= 0 && posicion < utilizados)
        {
            int tope = utilizados - 1;

            for (int i = posicion; i < tope; i++)
                v[i] = v[i + 1];

            utilizados--;
        }

    }

    /////////////////////////////////////////////////////////////
    // Algoritmos de ordenación

    void Ordena_por_Seleccion()
    {
        int pos_min;

        for (int izda = 0; izda < utilizados; izda++)
        {
            pos_min = PosMinimoEntre(izda, utilizados - 1);
            IntercambiaComponentesDirectamente(izda, pos_min);
        }
    }

    void Ordena_por_Insercion()
    {
        int izda, i;
        char a_desplazar;

        for (izda = 1; izda < utilizados; izda++)
        {
            a_desplazar = v[izda];

            for (i = izda; i > 0 && a_desplazar < v[i - 1]; i--)
                v[i] = v[i - 1];

            v[i] = a_desplazar;
        }
    }

    void InsertaOrdenadamente(char valor_nuevo)
    {
        int i;

        if (utilizados > TAMANIO)
        {
            for (i = utilizados; i > 0 && valor_nuevo < v[i - 1]; i--)
                v[i] = v[i - 1];

            v[i] = valor_nuevo;
            utilizados++;
        }
    }

    void Ordena_por_Burbuja()
    {
        int izda, i;

        for (izda = 0; izda < utilizados; izda++)
            for (i = utilizados - 1; i > izda; i--)
                if (v[i] < v[i - 1])
                    IntercambiaComponentesDirectamente(i, i - 1);
    }

    void Ordena_por_BurbujaMejorado()
    {
        int izda, i;
        bool cambio;

        cambio = true;

        for (izda = 0; izda < utilizados && cambio; izda++)
        {
            cambio = false;

            for (i = utilizados - 1; i > izda; i--)
                if (v[i] < v[i - 1])
                {
                    IntercambiaComponentesDirectamente(i, i - 1);
                    cambio = true;
                }
        }
    }

    void AniadeVarios(SecuenciaCaracteres nuevos)
    {
        int totales_a_aniadir = nuevos.Utilizados();

        for (int i = 0; i < totales_a_aniadir; i++)
            Aniade(nuevos.Elemento(i));
    }

    SecuenciaCaracteres ToUpper()
    {
        SecuenciaCaracteres en_mayuscula;

        for (int i = 0; i < utilizados; i++)
            en_mayuscula.Aniade(toupper(v[i]));

        return en_mayuscula;
    }

    int PosContiene(int izda, int dcha, SecuenciaCaracteres a_buscar)
    {
        int inicio;
        int ultimo;
        bool encontrado;
        int pos_contiene;
        bool va_coincidiendo;
        int util_a_buscar;


        util_a_buscar = a_buscar.Utilizados();

        if (util_a_buscar > 0)
        {
            ultimo = dcha + 1 - util_a_buscar;
            encontrado = false;

            for (inicio = izda; inicio <= ultimo && !encontrado; inicio++)
            {
                va_coincidiendo = true;

                for (int i = 0; i < util_a_buscar && va_coincidiendo; i++)
                    va_coincidiendo = v[inicio + i] == a_buscar.Elemento(i);

                if (va_coincidiendo)
                {
                    pos_contiene = inicio;
                    encontrado = true;
                }
            }
        }
        else
            encontrado = false;

        if (encontrado)
            return pos_contiene;
        else
            return -1;
    }

    int PosContiene(SecuenciaCaracteres a_buscar)
    {
        return PosContiene(0, utilizados - 1, a_buscar);
    }

    void InsertaSecuencia(int pos_insercion, SecuenciaCaracteres a_insertar)
    {
        int longitud_a_insertar = a_insertar.Utilizados();

        if (longitud_a_insertar + utilizados < TAMANIO)
        {
            for (int i = 0; i < longitud_a_insertar; i++)
            {
                Inserta(pos_insercion, a_insertar.Elemento(i)); // Inserta aumenta automáticamente utilizados
                pos_insercion++;
            }
        }
    }

    FrecuenciaCaracter moda(){
        char caracter;
        FrecuenciaCaracter moda; moda.frecuencia = 0;
        bool encontrado = false;
        char procesados[256]; int util_procesados = 0;

        for (int i = 0; i < utilizados; i++){
            caracter = v[i];
            encontrado = false;
            int repeticiones;
            for (int j = 0; j < util_procesados && !encontrado; j++){
                if (caracter == procesados[j])
                    encontrado = true;
            }

            if (!encontrado)
            {
                procesados[util_procesados] = caracter;
                util_procesados++;
                repeticiones = 0;

                for (int k = i; k < utilizados; k++)
                    if (caracter == v[k])
                        repeticiones++;

                if (repeticiones > moda.frecuencia)
                {
                    moda.frecuencia = repeticiones;
                    moda.caracter = caracter;
                }
            }
        }
        return moda;
    }
};

int main (){
    const char TERMINADOR = '#';

    SecuenciaCaracteres secuencia;
    FrecuenciaCaracter moda;
    char car;


    car = cin.get();
    while (car != TERMINADOR)
    {
        secuencia.Aniade(car);
        car = cin.get();
    }
    moda = secuencia.moda();

    cout << endl <<  moda.caracter << " " << moda.frecuencia << endl;
}
