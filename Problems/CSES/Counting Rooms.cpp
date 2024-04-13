#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

string rooms[1005];
bool visitados[1005][1005];
int n, m, moves_i[] = {-1, 1, 0, 0};
int moves_j[] = {0, 0, -1, 1};

void dfs(int i, int j) {
    visitados[i][j] = true;
    rooms[i][j] = '#';
    rep(k, 4) {
        int i2 = i + moves_i[k], j2 = j + moves_j[k];
        if (0 <= i2 && i2 < n && 0 <= j2 && j2 < m && !visitados[i2][j2])
            dfs(i2, j2);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int count = 0;
    cin >> n >> m;
    rep(i, n) {
        cin >> rooms[i];
    }

    rep(i, n) {
        rep(j, m) {
            if (rooms[i][j] == '.') {
                dfs(i, j);
                count++;
            }
        }
    }

    cout << count << '\n';

    return 0;
}