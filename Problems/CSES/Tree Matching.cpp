#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

int ans = 0;

int empareamientos_posibles(int node, int prev, vector<vector<int>>& tree) {
    // si estamos en una hoja retornamos 1
    if(tree[node].size() == 1 && tree[node][0] == prev) {
        return 1;
    } else {
        int num_empareamientos_posibles = 0;
        for(int vecino : tree[node]) {
            if(vecino != prev) {
                num_empareamientos_posibles += empareamientos_posibles(vecino, node, tree);
            }
        }
        if(num_empareamientos_posibles != 0) {
            ans++;
            return 0;
        } else
            return 1;
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

    int root = -1;

    // buscamos root
    rep(i, n) {
        if (tree[i].size() == 1) {
            root = i;
            break;
        }
    }

    // cout << "root: " << root << '\n';

    empareamientos_posibles(root, -1, tree);

    cout << ans << '\n';

    return 0;
}