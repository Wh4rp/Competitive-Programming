#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

void dfs(int node, int prev, vector<vector<int>>& tree, vector<int>& dist) {
    if (prev != -1)
        dist[node] = dist[prev] + 1;
    for (int vecino : tree[node]) {
        if (vecino != prev) {
            dfs(vecino, node, tree, dist);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int n;
    cin >> n;

    vector<vector<int>> tree(n);

    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    vector<int> dist(n);
    dist[0] = 0;
    dfs(0, -1, tree, dist);

    // buscamos el de mayor distancia
    int node_a = 0;
    rep(i, n) {
        if (dist[i] > dist[node_a])
            node_a = i;
    }

    // cout << "node a " << node_a << '\n';

    dist[node_a] = 0;

    dfs(node_a, -1, tree, dist);

    int node_b = 0;
    rep(i, n) {
        if (dist[i] > dist[node_b])
            node_b = i;
    }

    // cout << "node b " << node_b << '\n';

    cout << dist[node_b] << '\n';

    return 0;
}