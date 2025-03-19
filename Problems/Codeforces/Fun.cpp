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
        ll n, x, ans = 0;
        cin >> n >> x;
        for (ll a = 1; a <= n && a <= x; a++) {
            for (ll b = 1; a * b <= n && a + b <= x; b++) {
                ll k = min((n - a * b) / (a + b), x - (a + b));
                if(k > 0)
                    ans += k;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}