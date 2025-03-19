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
    int h, w, p , q;
    ll x;
    priority_queue<pair<ll, pair<int, int>>,
                vector<pair<ll, pair<int, int>>>,
                greater<pair<ll, pair<int, int>>>>
        cola;

    cin >> h >> w >> x >> p >> q;
    p--, q--;

    ll grid[h][w];
    bool visited[h][w];

    memset(visited, false, sizeof(visited));

    rep(i, h) rep(j, w) cin >> grid[i][j];

    ll curr_strength = 0;

    cola.push({grid[p][q], {p, q}});
    visited[p][q] = true;

    while (!cola.empty()) {
        ll strength = cola.top().first;
        int i = cola.top().second.first;
        int j = cola.top().second.second;
        cola.pop();
    
        if (curr_strength == 0 || (strength < (curr_strength + x - 1) / x)) {
            curr_strength += strength;
            int moves[] = {1, -1, 0, 0};
            rep(k, 4) {
                int ii = i + moves[k];
                int jj = j + moves[3 - k];
                if (0 <= ii && ii < h && 0 <= jj && jj < w && !visited[ii][jj]) {
                    visited[ii][jj] = true;
                    cola.push({grid[ii][jj], {ii, jj}});
                }
            }
        } else
            break;
    }

    cout << curr_strength << '\n';

    return 0;
}