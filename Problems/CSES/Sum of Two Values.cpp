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

    int n, x; cin >> n >> x;
    map<int, int> pos;
    int v[n]; rep(i, n) cin >> v[i];

    rep(i, n) {
        if(pos.count(x - v[i])){
            cout << i + 1 << ' ' << pos[x - v[i]] << '\n';
            return 0;
        }
        pos[v[i]] = i + 1;
    }
    cout << "IMPOSSIBLE\n";

    return 0;
}