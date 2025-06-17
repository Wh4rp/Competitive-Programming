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

    vector<ll> v(n), ac(n);

    rep(i, n) {
        cin >> v[i];
        ac[i] = v[i];
        if (i != 0)
            ac[i] += ac[i - 1];
    }

    cout << ac[n - 1] << '\n';

    if ((ac[n - 1] % 3) != 0) {
        cout << "0\n";
    } else {
        ll c1 = 0, ans = 0;
        rep(i, n) {
            if (ac[i] == 2 * ac[n - 1] / 3)
                c1++;
        }

        rep(i, n) {
            cout << c1 << ' ';
            if (ac[i] == 2 * ac[n - 1] / 3)
                c1--;
            if (ac[i] == ac[n-1] / 3)
                ans += c1;
        }
        cout << '\n';

        cout << ans << '\n';
    }

    return 0;
}