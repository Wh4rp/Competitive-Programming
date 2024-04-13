#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

bool check(int val, int max) {
    return 0 <= val && val < max;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool visited[2][n];
        rep(i, n) visited[0][i] = visited[1][i] = false;
        string grid[2];
        cin >> grid[0] >> grid[1];
        queue<pair<int, int>> q;
        q.push({0, 0});
        while (!q.empty()) {
            pair<int, int> pos = q.front();
            q.pop();
            int row = pos.first, col = pos.second;
            if (visited[row][col])
                continue;
            visited[row][col] = true;
            int moves[] = {1, -1, 0, 0};
            rep(i, 4) {
                int row2 = row + moves[i], col2 = col + moves[3 - i];
                if (check(row2, 2) && check(col2, n)) {
                    if (grid[row2][col2] == '<')
                        col2--;
                    else
                        col2++;
                    if (check(row2, 2) && check(col2, n)) {
                        q.push({row2, col2});
                    }
                }
            }
        }
        
        if (visited[1][n-1])
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}