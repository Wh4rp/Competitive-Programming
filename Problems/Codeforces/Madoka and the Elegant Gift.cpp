#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

bool visited[105][105];

int moves[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int x_min, x_max, y_min, y_max, cnt, n, m;
string s[105];

void dfs(int x, int y) {
    visited[x][y] = true;
    cnt++;
    x_min = min(x_min, x);
    x_max = max(x_max, x);
    y_min = min(y_min, y);
    y_max = max(y_max, y);

    rep(i, 4) {
        int nx = x + moves[i][0], ny = y + moves[i][1];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] &&
            s[nx][ny] == '1') {
            dfs(nx, ny);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int t;
    cin >> t;
    while (t--) {
        memset(visited, 0, sizeof(visited));
        cin >> n >> m;
        rep(i, n) cin >> s[i];
        bool elegant = true;
        rep(i, n) {
            rep(j, m) {
                if (s[i][j] == '1' && !visited[i][j]) {
                    x_min = i, x_max = i, y_min = j, y_max = j, cnt = 0;
                    dfs(i, j);
                    if (cnt != (x_max - x_min + 1) * (y_max - y_min + 1)) {
                        elegant = false;
                        break;
                    }
                }
            }
            if (!elegant)
                break;
        }
        cout << (elegant ? "YES" : "NO") << '\n';
    }

    return 0;
}