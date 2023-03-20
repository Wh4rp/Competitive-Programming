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

    if (m != n - 1) {
        cout << "No\n";
        return 0;
    }

    vector<vector<int>> adj(n);

    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    rep(i, n) {
        if (adj[i].size() > 2) {
            cout << "No\n";
            return 0;
        }
    }

    bool visited[n] = {false};
    int count = 0;
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while (!q.empty()) {
        count++;
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                q.push(v);
                visited[u] = true;
            }
        }
    }

    if (count == n) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}