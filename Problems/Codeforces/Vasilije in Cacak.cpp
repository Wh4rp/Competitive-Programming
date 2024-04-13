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
        int n, k, x;
        cin >> n;
        if (2 * x > n * (n + 1)) {
            cout << "NO\n";
        } else {
            int l = 0, r = 0;
            ll ac = 0;
            rep_(i, 1, n + 1) {
                ac += i;
                l++;
                if (ac > x) {
                    l--;
                    ac -= i;
                }
                
            }
            rep_(i, 1, n + 1) {
                ac += n - i + 1;
                if (ac > x) {
                    r = i - 1;
                    break;
                }
            }
            if (l <= x && x <= r) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}