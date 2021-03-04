#include <iostream>

using namespace std;

int main() {
    int entero;
    cin >> entero;

    if (entero < 0)
        entero = -entero;

    cout <<  entero;
}