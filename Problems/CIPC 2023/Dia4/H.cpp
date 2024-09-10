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

    int r, c, end_row, end_col, start_row, start_col;
    cin >> r >> c;
    string grid[r];
    vector<pair<int, int>> pokes;
    rep(i, r) {
        cin >> grid[i];
        rep(j, c) {
            if (grid[i][j] != 'T') {
                if (grid[i][j] == 'S') {
                    start_row = i;
                    start_col = j;
                } else if (grid[i][j] == 'E') {
                    end_row = i;
                    end_col = j;
                } else if (grid[i][j] != '0') {
                    pokes.push_back({i, j});
                }
            }
        }
    }

    bool visited[r][c];
    int distances[r][c];
    rep(i, r) rep(j, c) {
        distances[i][j] = -1;
        visited[i][j] = false;
    }
    queue<pair<int, int>> q;
    q.push({end_row, end_col});
    distances[end_row][end_col] = 0;

    int moves_row[] = {1, 0, -1, 0};
    int moves_col[] = {0, 1, 0, -1};

    while (!q.empty()) {
        pair<int, int> aux = q.front();
        q.pop();
        int row = aux.first;
        int col = aux.second;
        rep(i, 4) {
            int new_row = row + moves_row[i];
            int new_col = col + moves_col[i];
            if (0 <= new_row && new_row < r && 0 <= new_col && new_col < c &&
                !visited[new_row][new_col] && grid[new_row][new_col] != 'T') {
                q.push({new_row, new_col});
                distances[new_row][new_col] = distances[row][col] + 1;
                visited[new_row][new_col] = true;
            }
        }
    }

    int ans = 0;
    for (auto x : pokes) {
        if (distances[x.first][x.second] != -1 &&
            distances[x.first][x.second] <= distances[start_row][start_col]) {
            ans += grid[x.first][x.second] - '0';
        }
    }

    cout << ans << '\n';

    return 0;
}