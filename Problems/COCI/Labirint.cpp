#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

int colors_used(vector<int> colors) {
    return colors[0] + colors[1] + colors[2] + colors[3];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int n, m;
    cin >> n >> m;
    string righ_doors[n], down_doors[n - 1];
    rep(i, n) cin >> righ_doors[i];
    rep(i, n - 1) cin >> down_doors[i];

    int q;
    cin >> q;
    while (q--) {
        bool visited[n][m];
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--, c--, d--;
        int ans = 4;
        rep_(k, 1, 15) {
            memset(visited, false, sizeof(visited));
            queue<pair<int, int>> cola;

            map<char, int> colors_available = {
                {'P', k % 2},
                {'C', (k / 2) % 2},
                {'Z', (k / 4) % 2},
                {'N', (k / 8) % 2},
            };

            int count_colors =
                (k % 2) + ((k / 2) % 2) + ((k / 4) % 2) + ((k / 8) % 2);

            cola.push({a, b});
            visited[a][b] = true;

            while (!cola.empty()) {
                int i = cola.front().first;
                int j = cola.front().second;
                if (i == c && j == d)
                    break;
                cola.pop();
                int ii, jj;
                // derecha
                ii = i, jj = j + 1;
                if (0 <= ii && ii < n && 0 <= jj && jj < m &&
                    !visited[ii][jj] &&
                    colors_available[righ_doors[ii][jj - 1]]) {
                    cola.push({ii, jj});
                    visited[ii][jj] = true;
                }

                // izquierda
                ii = i, jj = j - 1;
                if (0 <= ii && ii < n && 0 <= jj && jj < m &&
                    !visited[ii][jj] && colors_available[righ_doors[ii][jj]]) {
                    cola.push({ii, jj});
                    visited[ii][jj] = true;
                }

                // abajo
                ii = i + 1, jj = j;
                if (0 <= ii && ii < n && 0 <= jj && jj < m &&
                    !visited[ii][jj] &&
                    colors_available[down_doors[ii - 1][jj]]) {
                    cola.push({ii, jj});
                    visited[ii][jj] = true;
                }

                // arriba
                ii = i - 1, jj = j;
                if (0 <= ii && ii < n && 0 <= jj && jj < m &&
                    !visited[ii][jj] && colors_available[down_doors[ii][jj]]) {
                    cola.push({ii, jj});
                    visited[ii][jj] = true;
                }
            }

            if (visited[c][d]) {
                ans = min(ans, count_colors);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}