#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

int k1, k2;
ll dp[105][105][30];

ll fun(int s, int c, int l) {
    if (s < 0 || c < 0) {
        return 0;
    }
    if (l < 0 && -1 * l > k1) {
        return 0;
    }
    if (l > 0 && l > k2) {
        return 0;
    }
    if (s + c == 0) {
        return 1;
    }
    if (dp[s][c][l + 15] != -1) {
        return dp[s][c][l + 15];
    } else {
        return dp[s][c][l + 15] = (fun(s - 1, c, min(0, l) - 1) +
                                   fun(s, c - 1, max(0, l) + 1)) %
                                  100000000;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    rep(i, 105) rep(j, 105) rep(k, 30) dp[i][j][k] = -1;

    int n1, n2;
    cin >> n1 >> n2 >> k1 >> k2;
    cout << fun(n1, n2, 0) << '\n';

    return 0;
}