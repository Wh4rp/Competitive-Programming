#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

const ll MOD = 100000000;

int n1, n2, k1, k2;

ll dp[105][105][25];

// dp[a][b][++a | --b]

ll f(int footmen, int horsemen, int balance) {
    if (footmen < 0 || horsemen < 0 || balance < 0)
        return 0;
    if (dp[footmen][horsemen][balance] != -1)
        return dp[footmen][horsemen][balance];
    if (balance > 10 && balance - 10 > k1)
        return 0;
    if (balance < 10 && 10 - balance > k2)
        return 0;
    if (footmen == 0 && horsemen == 0)
        return 1;
    // Intentamos agregar un footmen
    ll result_add_footmen =
        f(footmen - 1, horsemen, (balance > 10 ? balance + 1 : 11));
    // Intentamos agregar un horsemen
    ll result_add_horsemen =
        f(footmen, horsemen - 1, (balance < 10 ? balance - 1 : 9));

    return dp[footmen][horsemen][balance] =
               (result_add_footmen + result_add_horsemen) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    rep(i, 105) rep(j, 105) rep(k, 25) dp[i][j][k] = -1;

    cin >> n1 >> n2 >> k1 >> k2;

    cout << f(n1, n2, 10) << '\n';

    return 0;
}