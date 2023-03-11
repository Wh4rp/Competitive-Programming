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
    int v[n+5];
    rep(i, n+5){
        v[i] = 2;
    }
    while (q--) {
        int e, x;
        cin >> e >> x;
        if (e != 3){
            v[x] -= e;
        }
        else{
            cout << (v[x] <= 0 ? "Yes" : "No") << '\n';
        }
    }

    return 0;
}