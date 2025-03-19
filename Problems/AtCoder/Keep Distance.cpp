#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

vector<vector<int>> ans;
int n, m;

void backtrack(vector<int>& v) {
    int d = v.size();
    if (d == n) {
        ans.push_back(v);
    } else {
        int curr = v[d - 1] + 10;
        while (curr + 10 * (n - d - 1) <= m) {
            v.push_back(curr);
            backtrack(v);
            v.pop_back();
            curr++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    cin >> n >> m;

    vector<int> w;

    rep_(i, 1, m + 1) {
        w.push_back(i);
        backtrack(w);
        w.pop_back();
    }

    cout << ans.size() << '\n';

    for (auto v : ans) {
        for (int x : v) {
            cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
}