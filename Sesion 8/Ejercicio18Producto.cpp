#include <iostream>

using namespace std;

int main () {

    const int MAX_FIL = 10, MAX_COL = 10;
    double matr1[MAX_FIL][MAX_COL], matr2[MAX_FIL][MAX_COL], C[MAX_FIL][MAX_COL];
    int util_fil1, util_col1, util_fil2, util_col2;

    cout << "\n*****MULTIPLICACION DE MATRICES(A*B)*****";
    cout << "\nIntroduzca el numero de filas y columnas de la matriz A: ";
    cin >> util_fil1;
    cin >> util_col1;

    for (int i = 0; i < util_fil1; i++)
        for (int j = 0; j < util_col1; j++)
            cin >> matr1[i][j];

    cout << "\nIntroduzca el numero de columnas de la matriz B: ";
    util_fil2 = util_col1;
    cin >> util_col2;

    for (int i = 0; i < util_fil2; i++)
        for (int j = 0; j < util_col2; j++)
            cin >> matr2[i][j];

    for (int i = 0; i < util_fil1; i++) {
        for (int j = 0; j < util_col2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < util_col1; k++) {
                C[i][j] = C[i][j] + matr1[i][k] * matr2[k][j];
            }
        }
    }

    cout << "\nEl resultado de A*B es: ";
    for (int i = 0; i < util_fil1; i++) {
        for (int j = 0; j < util_col2; j++) {
            cout << C[i][j] << "\t";
        }

        cout << "\n";
    }
}