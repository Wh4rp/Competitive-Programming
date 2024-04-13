// crypto[a] -> a
// crypto[b] -> b
// crypto[c] -> c

// finish[a] -> a
// finish[b] -> b
// finish[c] -> c

// a <-> b

// crypto[finish[a]] = b
// crypto[finish[b]] = a

// aux = crypto[finish[a]]
// finish[a] -> crypto[finish[b]]
// finish[b] -> crypto[aux]

// a -> c
// c -> a

// c <-> b === c -> b, b -> c

// a -> c -> b
// c -> a
// b -> c

// INFORMACION RELEVANTE QUE OCUPE:
// cual es el inicio_1 tal que termina en b, R: a
// cual es el inicio_2 tal que termina en c, R: b

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

    int m, n;

    cin >> m >> n;

    map<char, char> m;

    rep(i, 26) {
        m['a' + i] = 'a' + i;
    }

    rep(i, m) {
        char a, b, aux;
        cin >> a >> b;
        // Inicio que termina en a
        char inicio1 = m[a];
        // Inicio que termina en b
        char inicio2 = m[b];
    }

    rep(i, n) {
        string s;
        cin >> s;
        for (auto x : s) {
            cout << crypto[x];
        }
        cout << '\n';
    }

    return 0;
}