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
    while (t--){
        ll n, x, y, ans = 0;
        cin >> n >> x >> y;
        ll z; // gcm(x, y)
        z = x * y / __gcd(x, y);
        x = n / x;
        y = n / y;
        z = n / z;
        x -= z;
        y -= z;
        // cout << x << ' ' << y << ' ' << z << '\n';
        ans += (n * (n + 1)) / 2 - ((n - x)) * (n-x + 1) / 2;
        ans -= (y * (y + 1)) / 2;
        cout << ans << '\n';
    }

    return 0;
}