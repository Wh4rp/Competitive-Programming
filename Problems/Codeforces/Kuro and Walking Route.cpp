#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

int a, b;
int visited[300005];
vector<vector<int>> g(300005, vector<int>());

ll dfs(int u, int c) {
    visited[u] = 1;
    if (u == a || u == b)
        c++;
    ll ans = 0;
    for (int v : g[u]) {
        if (visited[v])
            continue;
        ans += dfs(v, c);
    }
    return ans + c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    ll n;
    cin >> n >> a >> b;
    vector<vector<int>> g(n + 1, vector<int>());
    rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    memset(visited, 0, sizeof(visited));
    ll x = dfs(a, -1);
    memset(visited, 0, sizeof(visited));
    ll y = dfs(b, -1);

    cout << n * (n - 1) - x * y << '\n';

    return 0;
}