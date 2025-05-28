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

    int n, q;

    cin >> n >> q;

    ll a[n];
    vector<ll> aux(n, 0);

    rep(i, n) {
        cin >> a[i];
    }

    rep(i, q) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        aux[l] += 1;
        if (r + 1 < n)
            aux[r + 1] -= 1;
    }

    rep_(i, 1, n) {
        aux[i] += aux[i - 1];
    }

    sort(a, a + n);
    sort(aux.begin(), aux.end());
    ll ans = 0;
    rep(i, n) {
        ans += a[i] * aux[i];
    }

    cout << ans << '\n';

    return 0;
}