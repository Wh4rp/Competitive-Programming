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

    vector<vector<pair<int, char>>> roads_from(n + 1), roads_to(n + 1);

    rep(i, m) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        roads_from[u].push_back({v, c});
        roads_to[v].push_back({u, c});
    }

    ll ans = 0;

    queue<pair<int, int>> palindromos;

    bool caminos_encontrados[n + 5][n + 5];
    memset(caminos_encontrados, false, sizeof(caminos_encontrados));

    for (int u = 1; u < n + 1; u++) {
        for (auto [v, c] : roads_from[u]) {
            if (!caminos_encontrados[u][v]) {
                palindromos.push({u, v});
                // cout << u << " " << v << '\n';
                caminos_encontrados[u][v] = true;
                // caminos_encontrados[v][u] = true;
            }
        }
        palindromos.push({u, u});
        caminos_encontrados[u][u] = true;
    }

    // cout << '\n';

    while (!palindromos.empty()) {
        // u -> v
        int u = palindromos.front().first;
        int v = palindromos.front().second;
        palindromos.pop();
        if (u != v)
            ans++;
        for (auto [uu, c1] : roads_to[u]) {
            for (auto [vv, c2] : roads_from[v]) {
                // uu u
                // vv v
                if (c1 == c2 && !caminos_encontrados[uu][vv]) {
                    palindromos.push({uu, vv});
                    // cout << uu << " " << u << ' ' << v << ' ' << vv << '\n';
                    caminos_encontrados[uu][vv] = true;
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}