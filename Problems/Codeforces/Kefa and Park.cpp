#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

vector<int> grafo[100000];
bool cats[100000];
int n, m;

bool is_leaf(int node, int parent) {
    return grafo[node].size() == 1 && node != 0;
}

int ans(int node, int parent, int catCount) {
    int count = 0;
    if (cats[node]) {
        catCount++;
    } else {
        catCount = 0;
    }

    if (catCount > m) {
        return 0;
    }

    if (is_leaf(node, parent)) {
        count++;
    }

    for (int vecino : grafo[node]) {
        if (vecino != parent) {
            count += ans(vecino, node, catCount);
        }
    }

    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    cin >> n >> m;

    rep(i, n) {
        cin >> cats[i];
    }

    rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }

    int result = ans(0, -1, 0);

    cout << result << '\n';

    return 0;
}