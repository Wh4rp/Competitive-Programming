#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;
const int mod = 1e9 + 7;

int dp[1000001];

int fun(int n){
    if(dp[n] != -1)
        return dp[n];
    int ac = 0;
    rep(i, max(6, n)){
        ac += fun(n -(i+1));
        ac %= mod;
    }
    return dp[n] = ac;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int n;
    cin >> n;
    rep(i, n+1) dp[i] = -1;
    dp[0] = 1;
    cout << fun(n) << '\n';

    return 0;
}