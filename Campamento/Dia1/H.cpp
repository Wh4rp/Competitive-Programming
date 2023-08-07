#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

int main() {
    ll n, aux;
    cin >> n;
    ll x[n + 1];
    ll a1, a2, a3;
    cout << "? 1 2\n";
    cin >> a1;
    cout << "? 2 3\n";
    cin >> a2;
    cout << "? 1 3\n";
    cin >> a3;
    x[0] = (a1 + a3 - a2) / 2;
    x[1] = (a2 + a1 - a3) / 2;
    x[2] = (a3 + a2 - a1) / 2;

    rep_(i, 3, n) {
        cout << "? 1 " << i + 1 << '\n';
        cin >> aux;
        x[i] = aux - x[0];
    }

    cout << "! ";
    rep(i, n) {
        cout << x[i] << " \n"[i == n - 1];
    }

    return 0;
}