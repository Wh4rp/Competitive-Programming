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

    int h, w, x, y, cont = 0;
    cin >> h >> w >> x >> y;
    x--, y--;
    string grid[h], moves;

    bool visited[h][w];

    memset(visited, true, sizeof(visited));

    rep(i, h) cin >> grid[i];

    cin >> moves;

    for(char move : moves) {
        int x1, y1;
        if (move == 'U') {
            x1 = x - 1;
            y1 = y;
        } else if (move == 'D') {
            x1 = x + 1;
            y1 = y;
        } else if (move == 'L') {
            x1 = x;
            y1 = y - 1;
        } else {
            x1 = x;
            y1 = y + 1;
        }
        if(0 <= x1 && x1 < h && 0 <= y1 && y1 < w) {
            if(grid[x1][y1] != '#') {
                x = x1;
                y = y1;
                if(grid[x1][y1] == '@') {
                    cont += visited[x1][y1];
                    visited[x1][y1] = false;
                }
            }
        }
    }

    cout << x + 1 << ' ' << y + 1 << ' ' << cont << '\n';

    return 0;
}