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

    int n, m;
    cin >> n >> m;

    int up[n][m], left[n][m];

    rep(i, n)
        rep(j, m)
            cin >> up[i][j];
    rep(i, n)
        rep(j, m)
            cin >> left[i][j];
    
    int dp[n][m];

    dp[0][0] = 0;
    rep(i, n){
        rep(j, m){ 
            if(i == 0 && j == 0)
                continue;
            else if(i == 0)
                dp[i][j] = dp[i][j - 1] + left[i][j];
            else if(j == 0)
                dp[i][j] = dp[i-1][j] + up[i][j];
            else
                dp[i][j] = max(dp[i][j - 1] + left[i][j], dp[i-1][j] + up[i][j]);
        }
    }

    cout << dp[n-1][m-1] << '\n';

    return 0;
}