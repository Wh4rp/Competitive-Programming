#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep_(i, k, n) for (ll i = k; i < n; ++i)
using ll = long long;

ll calculate_size(ll u, ll p, vector<vector<ll>>& tree, vector<ll>& sz) {
    if (tree[u].size() == 1 && p != -1) {
        sz[u] = 1;
        return 1;
    }
    ll size_sub_tree = 1;
    for (ll v : tree[u]) {
        if (v != p) {
            size_sub_tree += calculate_size(v, u, tree, sz);
        }
    }

    sz[u] = size_sub_tree;

    return sz[u];
}

ll calculate_ans_root(ll u, ll p, ll depth, vector<vector<ll>>& tree) {
    if (tree[u].size() == 1 && p != -1) {
        return depth;
    }
    ll depth_sum = depth;
    for (ll v : tree[u]) {
        if (v != p) {
            depth_sum += calculate_ans_root(v, u, depth + 1, tree);
        }
    }
    return depth_sum;
}

void calculate_ans(ll u,
                   ll p,
                   ll n,
                   vector<vector<ll>>& tree,
                   vector<ll>& sz,
                   vector<ll>& ans) {
    if (p != -1)
        ans[u] = ans[p] + n - 2 * sz[u];

    for (ll v : tree[u]) {
        if (v != p) {
            calculate_ans(v, u, n, tree, sz, ans);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    ll n;
    cin >> n;

    vector<vector<ll>> tree(n);

    rep(i, n - 1) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    vector<ll> sz(n, -1);
    vector<ll> ans(n, -1);

    ll root = 0;
    calculate_size(root, -1, tree, sz);
    ans[0] = calculate_ans_root(root, -1, 0, tree);
    calculate_ans(root, -1, n, tree, sz, ans);

    for (ll a : ans) {
        cout << a << ' ';
    }
    cout << '\n';

    return 0;
}