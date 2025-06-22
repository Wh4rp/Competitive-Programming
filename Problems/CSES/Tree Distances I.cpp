#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;

#ifdef LOCAL
template<typename T> void __dbg(const T& x) { cerr << x; }
template<typename T, typename U> void __dbg(const pair<T, U>& p) {
    cerr << '('; __dbg(p.first); cerr << ", "; __dbg(p.second); cerr << ')';
}
template<typename T> void __dbg(const vector<T>& v) {
    cerr << '[';
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) cerr << ", ";
        __dbg(v[i]);
    }
    cerr << ']';
}
#define dbg(x) cerr << #x << " = "; __dbg(x); cerr << '\n';
#else
#define dbg(x)
#endif

// BFS que retorna vector de distancias desde src
vector<int> bfs_distances(const vector<vector<int>>& g, int src) {
    vector<int> d(g.size(), -1);
    queue<int> q;
    d[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (d[v] == -1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    return d;
}

// Retorna nodo más lejano desde src y su distancia
pair<int, int> farthest(const vector<vector<int>>& g, int src) {
    vector<int> d = bfs_distances(g, src);
    int node = src;
    for (int i = 0; i < (int)d.size(); ++i) {
        if (d[i] > d[node]) node = i;
    }
    dbg(node);
    dbg(d[node]);
    return {node, d[node]};
}

// Alias directo de bfs_distances
vector<int> get_distances(const vector<vector<int>>& g, int src) {
    return bfs_distances(g, src);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> g(n);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // Encontramos los extremos del diámetro
    auto [u, _] = farthest(g, 0);
    auto [v, diam] = farthest(g, u);

    dbg(u); dbg(v); dbg(diam);

    vector<int> d1 = get_distances(g, u);
    vector<int> d2 = get_distances(g, v);

    // Para cada nodo, su distancia máxima a u o v
    rep(i, n) {
        cout << max(d1[i], d2[i]) << ' ';
    }
    cout << '\n';
}
