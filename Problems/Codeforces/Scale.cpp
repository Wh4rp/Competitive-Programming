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
        int n, k;
        cin >> n >> k;
        string grid[n];
        rep(i, n) cin >> grid[i];
        rep(i, n / k) {
            rep(j, n / k) cout << grid[i * k][j * k];
            cout << '\n';
        }
    }

    return 0;
}