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

    ll pow10[5005];

    pow10[0] = 1;

    rep_(i, 1, 5005) {
        pow10[i] = (pow10[i - 1] * 10) % 1000000007;
    }

    int t;
    cin >> t;
    while (t--) {
        ll N;
        cin >> N;
        if (N == 1) {
            cout << 10 << '\n';
        } else {
            ll ans = ((N / 2) * ((9 * pow10[(N + 1) / 2]) % 1000000007)) %
                     1000000007;

            cout << ans << '\n';
        }
    }

    return 0;
}