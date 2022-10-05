#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

vector<int> adj[105];
ll weight[105][105], visited[105];
ll ans = 0;

ll dfs(int u, ll aux){
    visited[u] = 1;
    for(auto v : adj[u]){
        if(visited[v] == 0){
            ans = max(ans, dfs(v, aux + weight[u][v]));
        }
    }
    visited[u] = 0;
    return aux;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    rep(i, 105) rep(j, 105) weight[i][j] = -1;
    rep(i, 105) visited[i] = 0;
    
    int n;
    cin >> n;
    rep(i, n) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        weight[u][v] = weight[v][u] = w;
    }

    dfs(0, 0LL);
    cout << ans << '\n';

    return 0;
}