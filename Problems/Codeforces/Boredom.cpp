#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

vector<ll> a, memo;
map<ll, ll> m;

ll dp(int pos) {
    if (pos == -1 || pos == -2)
        return 0;
    if (pos == 0)
        return memo[pos] = m[a[pos]] * a[pos];
    if (memo[pos] != -1)
        return memo[pos];

    // usar a[pos]
    ll sol1 = m[a[pos]] * a[pos];
    if (a[pos - 1] == a[pos] - 1)
        sol1 += dp(pos - 2);
    else
        sol1 += dp(pos - 1);

    // no usar a[pos]
    ll sol2 = dp(pos - 1);

    memo[pos] = max(sol1, sol2);

    return memo[pos];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int n;

    cin >> n;
    rep(i, n) {
        int x;
        cin >> x;
        if (!m[x])
            a.push_back(x);
        m[x]++;
    }

    sort(a.begin(), a.end());

    int N = a.size();

    memo.resize(N, -1);

    cout << dp(N - 1) << '\n';

    return 0;
}