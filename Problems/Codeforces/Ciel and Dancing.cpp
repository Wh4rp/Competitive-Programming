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

    int n, m;
    cin >> n >> m;
    cout << n + m - 1 << '\n';
    rep(i, n) cout << i + 1 << ' ' << 1 << '\n';
    rep_(i, 1, m) cout << 1 << ' ' << i + 1 << '\n';

    return 0;
}