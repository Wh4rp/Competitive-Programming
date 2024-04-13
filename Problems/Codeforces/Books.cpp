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

    ll n, t, acc_time = 0, ans = 0, l = 0, r = 0;
    cin >> n >> t;
    ll a[n];
    rep(i, n) cin >> a[i];

    while (l < n && r < n) {
        acc_time += a[r];
        while (acc_time > t) {
            acc_time -= a[l];
            l++;
        }

        ans = max(ans, (r - l + 1));
        r++;
    }

    cout << ans << '\n';

    return 0;
}