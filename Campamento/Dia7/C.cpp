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

    int n;
    cin >> n;
    ll x;
    cin >> x;
    int n1 = n / 2, n2 = n - n1;
    ll a[n1], b[n2];

    rep(i, n1) cin >> a[i];
    rep(i, n2) cin >> b[i];

    vector<ll> sums1, sums2;
    for (int i = 0; i < (1 << n1); i++) {
        ll sum = 0;
        rep(j, n1) {
            if ((1 << j) & i) {
                sum += a[j];
            }
        }
        sums1.push_back(sum);
    }
    for (int i = 0; i < (1 << n2); i++) {
        ll sum = 0;
        rep(j, n2) {
            if ((1 << j) & i) {
                sum += b[j];
            }
        }
        sums2.push_back(sum);
    }
    sort(sums1.begin(), sums1.end());
    sort(sums2.begin(), sums2.end());
    ll ans = 0;
    for (auto val : sums1) {
        ans += upper_bound(sums2.begin(), sums2.end(), x - val) -
               lower_bound(sums2.begin(), sums2.end(), x - val);
    }

    cout << ans << '\n';

    return 0;
}