#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep_(i, k, n) for (ll i = k; i < n; ++i)
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    ll n, ans = 0;
    cin >> n;
    vector<ll> v(n);
    rep(i, n) {
        cin >> v[i];
    }

    ll i = 0, j = 0;
    bool crescent = false;

    rep(k, n - 1) {
        if (v[k] <= v[k + 1] && !crescent) {
            crescent = true;
            i = k;
        }
        if (v[k] > v[k + 1] && crescent) {
            j = k;
            crescent = false;
        }
        if (!crescent) {
            ans = max(ans, min(v[j] - v[i], v[j] - v[k + 1]));
        }
    }

    cout << ans << '\n';

    return 0;
}