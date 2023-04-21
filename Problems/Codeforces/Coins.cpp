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
        ll n, k;
        cin >> n >> k;
        if (n % 2 == 0) {
            cout << "YES\n";
        } else {
            if (k % 2 == 0) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        }
    }

    return 0;
}