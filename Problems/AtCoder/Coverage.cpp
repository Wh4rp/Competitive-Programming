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

    int n, m, c, aux;
    cin >> n >> m;
    int S[m];

    rep(i, m) {
        S[i] = 0;
        cin >> c;
        rep(j, c) {
            cin >> aux;
            S[i] |= (1 << (aux-1));
        }
    }

    int ans = 0;

    rep_(i, 1, 1 << m) {
        aux = 0;
        rep(j, m) {
            if (i & (1 << j)) {
                aux |= S[j];
            }
        }
        if (aux == (1 << n) - 1) {
            ans += 1;
        }
    }

    cout << ans << '\n';

    return 0;
}