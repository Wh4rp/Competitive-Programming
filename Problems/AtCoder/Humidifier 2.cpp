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

    int h, w, d, ans = 0;
    cin >> h >> w >> d;
    string grid[h];
    rep(i, h) cin >> grid[i];

    rep(i1, h) rep(j1, w) rep(i2, h) rep(j2, w) {
        if ((i1 != i2 || j1 != j2) && grid[i1][j1] == '.' &&
            grid[i2][j2] == '.') {
            int ans_aux = 0;
            rep(i, h) rep(j, w) {
                if (grid[i][j] == '.') {
                    int d1 = abs(i - i1) + abs(j - j1);
                    int d2 = abs(i - i2) + abs(j - j2);
                    if (d1 <= d || d2 <= d)
                        ans_aux++;
                }
            }
            ans = max(ans, ans_aux);
        }
    }

    cout << ans << '\n';

    return 0;
}