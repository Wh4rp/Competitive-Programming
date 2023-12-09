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

    // [torre][piso]

    int n, m;
    cin >> n >> m;
    vector<vector<bool>> safe(n, vector<bool>(m, false));
    rep(i, n){
        int p;
        cin >> p;
        rep(j, p){
            int stage;
            cin >> stage;
            safe[i][stage] = true;
        }
    }
    vector<vector<int>> dp(n, vector<int>(m, 100000000));

    dp[0][m-1] = 0;

    rep_(i, 1, n){
        rep(j, m){
            if(safe[i][j]){
                rep(k, m){
                    if(k > j){
                        dp[i][j] = min(dp[i][j], dp[i-1][k]);
                    }
                    else{
                        dp[i][j] = min(dp[i][j], dp[i-1][k] + j - k);
                    }
                }
            }
            
        }
    }

    int ans = *min_element(dp[n-1].begin(), dp[n-1].end());

    cout << ans << '\n';

    return 0;
}