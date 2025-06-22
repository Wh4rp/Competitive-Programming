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

    int n, q;
    cin >> n >> q;

    vector<vector<int>> tree(n);
    vector<int> parent(n, -1);

    rep(i, n - 1) {
        int u;
        cin >> u;
        u--;
        tree[u].push_back(i + 1);
        parent[i + 1] = u;
    }

    // hacer el array time stamps

    vector<int> in(n, -1), out(n, -1);

    function<int(int, int, int)> dfs_ts = [&](int u, int p, int time) {
        in[u] = time;
        for (auto v : tree[u]) {
            if (v != p) {
                time = dfs_ts(v, u, time + 1);
            }
        }
        out[u] = time;
        return time;
    };

    dfs_ts(0, -1, 0);

    // hacer el mecanismos de dado dos nodos
    // saber si uno es ancestro de otro

    function<bool(int, int)> is_ancestor = [&](int u, int v) {
        if (u == -1)
            return true;
        if (in[u] <= in[v] && in[v] <= out[u])
            return true;
        return false;
    };

    int LOG = 32;
    vector<array<int, 32>> prev(n);

    rep(i, LOG) {
        rep(u, n) {
            if (i == 0) {
                prev[u][i] = parent[u];
            } else {
                if (prev[u][i - 1] != -1)
                    prev[u][i] = prev[prev[u][i - 1]][i - 1];
                else
                    prev[u][i] = -1;
            }
        }
    }

    function<int(int, int)> ancestor = [&](int u, int k) {
        int pow2 = 1, l = 0;
        while (pow2 <= k && u != -1) {
            if (pow2 & k) {
                u = prev[u][l];
            }
            pow2 *= 2;
            l++;
        }
        if (u != -1)
            return u;
        else
            return -1;
    };

    // hacer busqueda binaria
    function<int(int, int)> lca = [&](int u, int v) {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;

        int l = 1, r = 2e5;
        // seteamos u

        while (l < r) {
            int m = (l + r) / 2;
            int u_ancestor = ancestor(u, m);
            if (is_ancestor(u_ancestor, v))
                r = m;
            else
                l = m + 1;
        }

        return ancestor(u, l);
    };

    rep(i, q) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        cout << lca(u, v) + 1 << '\n';
    }

    return 0;
}