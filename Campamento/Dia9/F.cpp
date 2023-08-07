#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

template <class T>
struct Hash {
    long long m;  // Modulo, opciones: 1e9+7, 1e9+9, 1e9+123
    long long b;  // Base, mayor que el numero de elementos distintos.
                  // Algunos dicen que mayor al mayor valor de los elementos.
                  // Opciones: 31, 127, 139
    std::vector<long long> pot, H;
    int n;
    Hash(T& s, long long b = 127, long long m = 1e9 + 123)
        : b(b), m(m), n(s.size()) {
        pot.resize(n + 1);
        H.resize(n + 1);
        H[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; i--)
            H[i] = (s[i] + H[i + 1] * b) % m;
        pot[0] = 1;
        for (int i = 1; i <= n; i++)
            pot[i] = (pot[i - 1] * b) % m;
    }
    // Calcula el hash del substring que parte en i de largo k.
    // k debera ser mayor a 0.
    long long hash(int i, int k) {
        if (i + k <= n)
            return (m + H[i] - (H[i + k] * pot[k] % m)) % m;
        return (hash(i, n - i) + hash(0, k - (n - i)) * pot[n - i]) % m;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        set<ll> hashes;
        Hash<string> h1(s), h2(s, 31, 1e9 + 7);
        rep(i, n - k + 1) {
            hashes.insert(h1.hash(i, k) | (h2.hash(i, k) << 32));
        }
        cout << hashes.size() << '\n';
    }
    return 0;
}