#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

const ll MOD = 1000000007;

ll k, dp[100005];

ll f(ll x) {
    if (x < 0)
        return 0;
    if(x == 0)
        return 1LL;
    if (dp[x] != -1)
        return dp[x];
    if (x < k)
        return dp[x] = f(x - 1);
    if (x == k)
        return dp[x] = (f(x - k) + f(x - 1)) % MOD;
    return dp[x] = (f(x - k) + f(x - 1)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    rep(i, 100005) dp[i] = -1;
    int t;
    cin >> t >> k;

    f(100003);

    ll acc_sum[100005];
    acc_sum[0] = 1;
    rep_(i, 1, 100002) acc_sum[i] = (dp[i] + acc_sum[i - 1]) % MOD;

    while (t--) {
        ll a, b;
        cin >> a >> b;
        cout << (MOD + (acc_sum[b] - acc_sum[a - 1]) % MOD) % MOD << '\n';
    }

    return 0;
}