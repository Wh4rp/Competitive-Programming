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
 
    function<int(ll, ll)> dfs_height = [&](ll u, ll p) {
        int max_height = 1;
        for (auto v : tree[u]) {
            if (v != p) {
                max_height = max(max_height, 1 + dfs_height(v, u));
            }
        }
        return max_height;
    };
 
    int height = dfs_height(0, -1);
    int log_2 = 32, pow2 = 1;
    int prev[n][log_2];
 
    rep(i, log_2) {
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
 
    rep(i, q) {
        int x, k;
        cin >> x >> k;
        pow2 = 1;
        int u = x - 1, l = 0;
        // cout << "buscando prev de " << u << " en " << k << " arriba\n";
        while (pow2 <= k && u != -1) {
            if (pow2 & k) {
                u = prev[u][l];
            }
            // cout << u << '\n';
            pow2 *= 2;
            l++;
        }
        if (u != -1)
            cout << u + 1 << '\n';
        else
            cout << "-1\n";
    }
 
    return 0;
}