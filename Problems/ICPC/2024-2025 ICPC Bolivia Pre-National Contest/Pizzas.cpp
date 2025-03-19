#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

bool visited[100005];
vector<int> graph[100005];

const int MOD = 1e9 + 7;

ll dfs(int u) {
    ll ans = 0;
    visited[u] = true;
    for(int v : graph[u]) {
        if(!visited[v]) 
        ans += dfs(v);
    }

    return ans + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int n, m;
    cin >> n >> m;

    memset(visited, 0, sizeof(visited));

    rep(i, m){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    ll ans = 1;

    rep_(i, 1, n + 1) {
        ans *= dfs(i);
        ans %= MOD;
    }

    cout << ans << '\n';

    return 0;
}