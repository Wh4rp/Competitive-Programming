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
        ll n, a, b;
        cin >> n >> a >> b;
        ll d = __gcd(a, b);
        ll c[n];
        rep(i, n) {
            cin >> c[i];
            c[i] %= d;
        }

        sort(c, c + n);
        
        ll ans = c[n-1] - c[0];

        rep_(i, 1, n) {
            ans = min(ans, c[i-1] + d - c[i]);
        }

        cout << ans << '\n';
    }

    return 0;
}