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
        int b[n - 1];
        rep(i, n - 1) {
            cin >> b[i];
        }
        cout << b[0] << ' ';
        rep(i, n - 2){
            cout << min(b[i], b[i + 1]) << ' ';
        }
        cout << b[n-2] << '\n';
    }

    return 0;
}