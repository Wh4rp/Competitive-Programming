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

    int h, w, D, ans = 0;

    cin >> h >> w >> D;

    string grid[h];
    bool visited[h][w];

    memset(visited, false, sizeof(visited));

    rep(i, h) cin >> grid[i];

    queue<pair<int, pair<int, int>>> cola;

    rep(i, h) rep(j, w) {
        if(grid[i][j] == 'H') {
            cola.push({D, {i, j}});
        }
    }

    vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    while(!cola.empty()) {
        int d = cola.front().first;
        int i = cola.front().second.first, j = cola.front().second.second;
        cola.pop();
        if(!visited[i][j]) ans++;
        visited[i][j] = true;
        if(d == 0) continue;
        for(auto move : moves) {
            int ii = i + move.first;
            int jj = j + move.second;
            if(0 <= ii && ii < h && 0 <= jj && jj < w) {
                if(!visited[ii][jj] && grid[ii][jj] != '#')
                    cola.push({d-1, {ii, jj}});
            }
        }
    }

    cout << ans << '\n';

    return 0;
}