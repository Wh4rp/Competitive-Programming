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
        ll n, ans = 0;
        cin >> n;
        ll a[n], b[n];
        rep(i, n) {
            cin >> a[i];
            b[i] = -1;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (i + a[i] > n - 1) {
                b[i] = a[i];
            } else {
                b[i] = a[i] + b[i + a[i]];
            }
        }

        cout << *max_element(b, b + n) << '\n';
    }

    return 0;
}