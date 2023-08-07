#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

int r, c;
set<ll> numbers_seen;
ll grid[10][10];

ll back_tracking(int i, int j) {
    if (i == r - 1 && j == c - 1)
        return 1;
    ll down_move = 0, right_move = 0;
    if (i + 1 <= r - 1 && numbers_seen.count(grid[i + 1][j]) == 0) {
        numbers_seen.insert(grid[i + 1][j]);
        down_move = back_tracking(i + 1, j);
        numbers_seen.erase(grid[i + 1][j]);
    }
    if (j + 1 <= c - 1 && numbers_seen.count(grid[i][j + 1]) == 0) {
        numbers_seen.insert(grid[i][j + 1]);
        right_move = back_tracking(i, j + 1);
        numbers_seen.erase(grid[i][j + 1]);
    }
    return down_move + right_move;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    cin >> r >> c;

    rep(i, r) rep(j, c) cin >> grid[i][j];

    numbers_seen.insert(grid[0][0]);

    cout << back_tracking(0, 0) << '\n';

    return 0;
}