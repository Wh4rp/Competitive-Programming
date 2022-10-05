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

    int n, k;
    cin >> n >> k;
    vector<ll> a(n), t(n), b(n), c(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> t[i];
    rep(i, n) {
        b[i] = a[i] * (1-t[i]);
        c[i] = a[i] * t[i];
    }
    ll s[n];
    partial_sum(b.begin(), b.end(), s);
    ll ans = s[k-1];
    rep(i, n - k){
        ans = max(ans, s[k+i] - s[i]);
    }
    ans += accumulate(c.begin(), c.end(), 0LL);
    cout << ans << '\n';

    return 0;
}