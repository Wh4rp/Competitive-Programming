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
    string draw[n];

    rep(i, n) cin >> draw[i];

    vector<pair<pair<int, int>, char>> moves = {
        {{0, 1}, '-'},     // right
        {{-1, 1}, '/'},    // right_up
        {{-1, 0}, '|'},    // up
        {{-1, -1}, '\\'},  // up_left
        {{0, -1}, '-'},    // left
        {{1, -1}, '/'},    // left_down
        {{1, 0}, '|'},     // down
        {{1, 1}, '\\'},    // down_right
    };

    auto check_bounds = [n, m](int i, int j) {
        return 0 <= i && i < n && 0 <= j && j < m;
    };

    auto check_move = [&](int i, int j, int level, pair<int, int> move,
                          char stroke) -> bool {
        int ii = i + level * move.first;
        int jj = j + level * move.second;
        return check_bounds(ii, jj) && draw[ii][jj] == stroke;
    };

    auto check_moves = [&](int i, int j, int level) -> bool {
        for (auto [move, stroke] : moves) {
            if (!check_move(i, j, level, move, stroke))
                return false;
        }
        return true;
    };

    int ans = 0;

    rep(i, n) rep(j, m) {
        if (draw[i][j] == '+') {
            int level = 1;
            while (check_moves(i, j, level)) {
                level++;
            }
            ans = max(ans, level - 1);
        }
    }

    cout << ans << '\n';

    return 0;
}