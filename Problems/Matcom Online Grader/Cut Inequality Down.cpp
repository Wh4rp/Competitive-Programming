#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    /*
    Sketch de la solución:

    1. Hacer un array de suma acumulada
    2. Hacer un segment tree que guarde el mayor y el menor en rango
    3. Para cada elemento de A-i reviso cual es el próximo
    c = A[j] + U tal que c < L o C > U.
    Hago lo mismo con c' = A[j] + L
    Esto se puede hacer con búsqueda binaria y el segment tree
    Y conectamos i-U y i-L con j-L o j-U según corresponda
    Esto nos va a formar un árbol. Y le sacamos el binary lifting al árbol

    4. Para cada query lo que hacemos es buscar el próximo A[j] tal que 
    c = A[j] + X tal que c < L o C > U.
    Si este j es mayor que el mes que nos piden entonces retornamos
    X + sum_ac[i, E]
    Si no entonces nos posicionamos en A[j] y vemos si somos L o U. 
    Y hacemos binarylifting hasta encontrar el mayor j' que no se 
    pase de E. Y cuando no se pase entonces retornamos U o L + sum_ac[j', E].

    */

    return 0;
}