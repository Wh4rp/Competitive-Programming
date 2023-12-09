#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

// function binsearch(array, i, j) {
//     // assert(i < j) // since the range is [i,j), then j must be > i
//     while (i < j) {
//         m = (i+j) / 2;
//         if (predicate(array[m]))
//             j = m
//         else
//             i = m + 1
//     }
//     return i; // notice that i == j if the predicate is false for the whole
//     range
// }

// First time that (b-k)^2 - 4ac >= 0
// (b-k) positivo
ll bin_search_pos(ll a, ll b, ll c) {
    ll i = b, j = 1e9, m;
    while (i < j) {
        m = (i + j) / 2;
        if (((m - b) * (m - b) - 4 * a * c) >= 0)
            j = m;
        else
            i = m + 1;
    }
    return i;
}

// First time that (b-k)^2 - 4ac <= 0
// (b-k) negativo
ll bin_search_neg(int a, int b, int c) {
    ll i = -1e9, j = b, m;
    while (i < j) {
        m = floor((i + j) * 0.5);
        // cout << "i: " << i << " j: " << j << '\n';
        // cout << "m: " << m << '\n';
        // cout << ((b - m) * (b - m) - 4 * a * c) << '\n';
        if (((b - m) * (b - m) - 4 * a * c) <= 0)
            j = m;
        else
            i = m + 1;
        // int aux;
        // cin >> aux;
    }
    return i;
}

// Primer indice tal que es mayor a k
int bin_search(vector<ll>& lines, int k) {
    int i = 0, j = lines.size() - 1, m;
    while (i < j) {
        // cout << i << ' ' << j << '\n';
        m = (i + j) / 2;
        if (lines[m] > k)
            j = m;
        else
            i = m + 1;
    }
    if (lines[i] <= k)
        return i + 1;
    return i;
}

bool check(ll a, ll b, ll c){
    return ((b * b) - 4 * a * c) >= 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<ll> lines(n);
        rep(i, n) cin >> lines[i];
        sort(lines.begin(), lines.end());
        rep(i, n) cout << lines[i] << ' ';
        cout << '\n';
        rep(i, m) {
            ll a, b, c;
            cin >> a >> b >> c;
            cout << "La ecuación es: " << a << "x^2 + " << b << "x + " << c
                 << '\n';
            ll k_max = bin_search_pos(a, b, c) - 1;
            ll k_min = bin_search_neg(a, b, c);

            cout << "k_max: " << k_max << '\n';
            cout << "k_min: " << k_min << '\n';
            // Ultimo indice de un valor en lines tal que sea menor a k_max
            int it_max = bin_search(lines, k_max) - 1;
            cout << "it_max: " << it_max << '\n';
            // Primer indice de un valor en lines tal que sea mayor a k_min
            int it_min = bin_search(lines, k_min);
            // Idea: ver tres casos al rededor de it_min y it_max
            bool flag = true;
            int near[] = {-2, -1, 0, 1, 2};
            for (int i : near) {
                if(0 <= it_min + i && it_min + i < n){
                    if(check(a, b - lines[it_min + i], c)){
                        cout << "YES\n";
                        flag = false;
                        break;
                    }
                }
                if(0 <= it_max + i && it_max + i < n){
                    if(check(a, b - lines[it_max + i], c)){
                        cout << "YES\n";
                        flag = false;
                        break;
                    }
                }
            }
            cout << "it_min: " << it_min << '\n';
            if(flag)
                cout << "NO\n";
        }
    }

    return 0;
}