#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

const ll MOD = 1000000007LL;

ll dp[1000005][2][2][2];

ll fun(int n, int l, int r, int up) {
    if (dp[n][l][r][up] != -1)
        return dp[n][l][r][up];

    if (n == 0) {
        if (l + r == 2) {
            // cout << s << '\n';
            return 1LL;
        } else
            return 0LL;
    }

    if (l + r == 2) {
        return dp[n][l][r][up] =
                   (2 * fun(n - 1, 1, 1, 1) + 2 * fun(n - 1, 1, 0, 1) +
                    2 * fun(n - 1, 1, 0, 0) + fun(n - 1, 0, 0, 1) +
                    fun(n - 1, 0, 0, 0)) %
                   MOD;
    }

    if (up == 1 && (l + r == 1)) {
        return dp[n][l][r][up] =
                   (fun(n - 1, 0, 0, 1) + 2 * fun(n - 1, 1, 0, 1) +
                    fun(n - 1, 1, 1, 1)) %
                   MOD;
    }

    if (l + r + up == 0) {
        return dp[n][l][r][up] =
                   (fun(n - 1, 0, 0, 0) + fun(n - 1, 1, 1, 0)) % MOD;
    }

    if (l + r == 0 && up == 1) {
        return dp[n][l][r][up] = (fun(n - 1, 0, 0, 1) + fun(n - 1, 1, 1, 1) +
                                  2 * fun(n - 1, 1, 0, 1)) %
                                 MOD;
    }

    return 0LL;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        rep(i, n + 2) rep(j, 2) rep(k, 2) rep(l, 2) dp[i][j][k][l] = -1;
        cout << fun(n, 1, 1, 0) << '\n';
        cout << "1\n";
    }

    return 0;
}