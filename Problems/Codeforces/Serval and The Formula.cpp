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
        ll x, y, k = 0;
        cin >> x >> y;
        if(x == y) cout << "-1\n";
        else {
            x = max(x, y);
            // buscamos el pow2 mas peque;o que sea mayor que x
            ll pow2 = 1;
            while (pow2 <= x) {
                pow2 *= 2;
            }
            cout << (pow2 - x) << '\n';
        }
    }

    return 0;
}