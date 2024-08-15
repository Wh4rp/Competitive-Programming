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

    int n;
    int genoma = 0;
    
    while (cin >> n, n != 0) {
        genoma++;
        cout << "Genome " << genoma << '\n';
        // Crear vector de 1 -> n
        vector<int> v(n);
        rep(i, n) v[i] = i + 1;
        int r;
        cin >> r;
        rep(k, r){
            int i, j;
            cin >> i >> j;
            i--, j--;
            for (int l = i; l < (i + j + 1) / 2; l++) {
                swap(v[l], v[j - (l - i)]);
            }
        }
        vector<int> pos(n + 5);
        rep(i, n){
            pos[v[i]] = i + 1;
        }
        int Q;
        cin >> Q;
        rep(i, Q){
            int q;
            cin >> q;
            cout << pos[q] << '\n';
        }
    }

    return 0;
}