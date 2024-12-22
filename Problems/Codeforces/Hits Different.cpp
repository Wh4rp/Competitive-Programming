#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

int upperbound(ll key) {
    ll i = 1, j = 2023;
    while (i < j) {
        ll m = (i + j) / 2;
        if (m * (m + 1) >= key * 2)
            j = m;
        else
            i = m + 1;
    }
    return i;
}

ll up_left(ll n) {
    ll row = upperbound(n);
    ll relative_pos = n - (row - 1) * row / 2;
    if(relative_pos == 1) return 0;
    else return relative_pos - 1 + (row - 2) * (row - 1) / 2;
}

ll up_right(ll n) {
    ll row = upperbound(n);
    ll relative_pos = n - (row - 1) * row / 2;
    if(relative_pos == row) return 0;
    else return relative_pos + (row - 2) * (row - 1) / 2;
}

ll memo[2024*2024];

ll dp(ll n) {
    if (memo[n] != -1) return memo[n];
    if(n == 0)  return 0;
    else return memo[n] = n * n + dp(up_left(n));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int t;
    cin >> t;

    memset(memo, -1, sizeof(memo));

    while (t--) {
        int n;
        ll ans = 0;
        cin >> n;
        while(n != 0) {
            ans += dp(n);
            n = up_right(n);
        }

        cout << ans << '\n';
    }

    return 0;
}