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

    int n;
    cin >> n;
    string grid[n];
    vector<pair<int, int>> pos;
    rep(i, n) {
        cin >> grid[i];
        rep(j, n) {
            if (grid[i][j] != '.')
                pos.push_back({i, j});
        }
    }
    ll ans = 0;
    int m = pos.size();
    rep(i, m - 2) rep_(j, i + 1, m - 1) rep_(k, j + 1, m) {
        ll x[3] = {pos[i].first, pos[j].first, pos[k].first};
        ll y[3] = {pos[i].second, pos[j].second, pos[k].second};
        if ((x[0] == x[1] && x[1] == x[2]) ||
            ((x[0] - x[1]) * (y[0] - y[2])) ==
                ((x[0] - x[2]) * (y[0] - y[1]))) {
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}