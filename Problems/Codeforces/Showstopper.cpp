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
        int n;
        cin >> n;

        int a[n], b[n];
        rep(i, n) {
            cin >> a[i];
        }
        rep(i, n) {
            cin >> b[i];
        }
        if (n == 1) {
            cout << "YES" << endl;
            continue;
        }
        int maxi_a = 0, maxi_b = 0;
        rep(i, n - 1) {
            maxi_a = max(maxi_a, max(a[i], b[i]));
            maxi_b = max(maxi_b, min(a[i], b[i]));
        }
        if (maxi_a <= max(a[n - 1], b[n - 1]) &&
            maxi_b <= min(a[n - 1], b[n - 1])) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}