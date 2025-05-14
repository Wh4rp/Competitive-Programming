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

    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        ll ans = 0;
        cin >> n >> m;

        vector<ll> v(m);

        rep(i, m) {
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        for(int i = 1; i < n; i++) {
            int j = n - i;
            cout << "i: " << i << " j: " << j << '\n';
            // primer elemento no menor a i (me da el igual tambien)
            auto x = lower_bound(v.begin(), v.end(), i);
            auto pos = x - v.begin();
            int cant_menores_a_i = m - pos;
            if(pos == m) cant_menores_a_i = m;
            cout << "pos: " << pos << '\n';
            cout << "x: " << *x << '\n';
            cout << "cantidad menores a " << i << ": " << cant_menores_a_i << '\n';
            cout << '\n';
        }

        cout << ans << '\n';
    }

    return 0;
}