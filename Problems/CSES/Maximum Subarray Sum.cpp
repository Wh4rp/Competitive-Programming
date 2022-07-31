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

    int n; cin >> n;
    ll a[n]; rep(i, n) cin >> a[i];
    ll sum = 0, ans = LLONG_MIN;
    rep(i, n) {
        sum = max(a[i] + sum, a[i]);
        ans = max(ans, sum);
    }
    cout << ans << '\n';

    return 0;
}