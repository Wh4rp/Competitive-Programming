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

    ll l, n1, n2;
    cin >> l >> n1 >> n2;
    pair<ll, ll> A[n1], B[n2];
    rep(i, n1) cin >> A[i].first >> A[i].second;
    rep(i, n2) cin >> B[i].first >> B[i].second;
    ll i1 = 0, i2 = 0, ans = 0;

    while (i1 < n1 && i2 < n2) {
        ll add = min(A[i1].second, B[i2].second);
        A[i1].second -= add;
        B[i2].second -= add;
        if (A[i1].first == B[i2].first)
            ans += add;
        if (A[i1].second == 0)
            i1++;
        if (B[i2].second == 0)
            i2++;
    }

    cout << ans << '\n';

    return 0;
}