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

    // lista ligada con prev y next implementada con dos arrays
    int n;
    cin >> n;
    int p[n];
    rep(i, n) {
        cin >> p[i];
    }
    int next[n], prev[n];
    rep(i, n - 1) next[i] = p[i + 1];
    next[n - 1] = p[0];
    rep_(i, 1, n) prev[i] = p[i - 1];
    prev[0] = p[n - 1];

    int e;

    cin >> e;

    while (e--) {
        char op;
        cin >> op;

        if (op == '-') {
            int x;
            cin >> x;
            // eliminar x de la lista
            // actualizar next y prev
            // si x es el primero, actualizar el primero
            // si x es el ultimo, actualizar el ultimo

            prev[next[x]] = prev[x];
            next[prev[x]] = next[x];

            prev[x] = -1;
            next[x] = -1;
        } else if (op == '+') {
            int y, z;
            cin >> y >> z;
            // agregar y a la izquierda de z
            // actualizar next y prev
            int x = prev[y];

            next[x] = y;
            prev[z] = y;
            prev[y] = x;
            next[y] = z;
        } else if (op == '?') {
            
        }
    }

    return 0;
}