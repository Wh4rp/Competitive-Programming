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

    unordered_map<ll, ll> frec_sums1, frec_sums2;
    frec_sums1.reserve(1<<n1);
    frec_sums2.reserve(1<<n2);
    for (int i = 0; i < (1 << n1); i++) {
        ll sum = 0;
        rep(j, n1) {
            if ((1 << j) & i) {
                sum += a[j];
            }
        }
        frec_sums1[sum]++;
    }
    for (int i = 0; i < (1 << n2); i++) {
        ll sum = 0;
        rep(j, n2) {
            if ((1 << j) & i) {
                sum += b[j];
            }
        }
        frec_sums2[sum]++;
    }
    ll ans = 0;
    for (auto y : frec_sums1) {
        ll val = y.first;
        ll frec = y.second;
        ans += frec * (frec_sums2[x - val]);
    }

    cout << ans << '\n';

    return 0;
}