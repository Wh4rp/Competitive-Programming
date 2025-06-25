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

    1. Ingresar el tree
    2. Calcular los nodos que forman el diamtero
        - A y B (int)
    3. Calcular la distancia de A y B a todos los nodos
        - D_A y D_B (arrays)
    4. Calcular el array de binary lifting
        - Up
    5. En cada query (v, d) ver a cual nodo está más lejos
    entre A o B. (asumamos A). Luego:
        5.1 Si la distancia es menor que d print 0
        5.2 Sino calcular el LCA entre v y A. Digamos C
            Ver su distancia a C de v y A.
            - dis_C_v, dis_A_v
            Si d <= dis_C_v, entonces ocupar binarylifting para 
            regresar nodo a esa altura de v
            Si d > dis_C_v entonces regresar nodo el nodo a distancia
            d - dis_A_v de A.

    */

    return 0;
}