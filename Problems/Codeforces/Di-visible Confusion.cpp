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

    int t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;
        vector<ll> a(n+1);
        rep(i, n) cin >> a[i+1];
        bool can = true;
        ll div = 1;
        rep_(i, 1, n+1) {
            div = (i+1) * div / __gcd((i+1), div);
            if (a[i] % div == 0) {
                can = false;
                break;
            }
        }
        if (can)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}