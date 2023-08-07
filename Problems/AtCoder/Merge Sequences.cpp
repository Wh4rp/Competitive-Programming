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
    int a[n], pos_a[n], b[m], pos_b[m];
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    int i1 = 0, i2 = 0;
    while (i1 < n && i2 < m) {
        if (a[i1] < b[i2]) {
            pos_a[i1] = i1 + i2;
            i1++;
        } else {
            pos_b[i2] = i1 + i2;
            i2++;
        }
    }
    while (i1 < n) {
        pos_a[i1] = i1 + i2;
        i1++;
    }
    while (i2 < m) {
        pos_b[i2] = i1 + i2;
        i2++;
    }

    rep(i, n) cout << pos_a[i] + 1 << ' ';
    cout << '\n';
    rep(i, m) cout << pos_b[i] + 1 << ' ';
    cout << '\n';

    return 0;
}