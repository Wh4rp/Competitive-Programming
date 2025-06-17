#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

// Maximos arboles talados hasta
// el i-esimo arbol, si el arbol i+1 cayo a la izquierda
ll memo[100005][2];
int n;

int x[100005], h[100005];

ll dp(int i, int dir) {
    ll ans;

    if (memo[i][dir] != -1)
        return memo[i][dir];

    if (i == 0)
        return 1;

    int tope_derecho = 1e10;
    if (i != n - 1) {
        if (dir == 0)
            tope_derecho = x[i + 1];
        else
            tope_derecho = x[i + 1] - h[i + 1];
    }

    int cor_cae_derecho = x[i] + h[i];

    if (cor_cae_derecho < tope_derecho) {
        ans = 1 + dp(i - 1, 0);
    } else {
        ans = dp(i - 1, 0);  // no talar

        int cor_cae_izquierda = x[i] - h[i];
        if (x[i - 1] < cor_cae_izquierda)
            ans = max(ans, 1 + dp(i - 1, 1));  // talar
    }

    return memo[i][dir] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    cin >> n;
    rep(i, n) cin >> x[i] >> h[i];

    rep(i, n) {
        memo[i][0] = -1;
        memo[i][1] = -1;
    }

    cout << dp(n - 1, 0) << '\n';

    return 0;
}