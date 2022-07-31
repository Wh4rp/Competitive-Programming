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

    int n, m, t, x; cin >> n >> m;
    multiset<int> h;
    rep(i, n) {
        cin >> x;
        h.insert(x);
    }
    rep(i, m){
        cin >> t;
        auto it = h.upper_bound(t);
        if(it != h.begin()){
            cout << *(--it) << '\n';
            h.erase(it);
        }
        else
            cout << -1 << '\n';
    }

    return 0;
}