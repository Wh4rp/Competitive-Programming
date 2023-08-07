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

    int n;
    cin >> n;
    vector<int> g(n);
    rep(i, n) {
        cin >> g[i];
        g[i]--;
    }
    bool flag = false;
    rep(i, n) {
        int a = i;
        int b = g[a];
        int c = g[b];
        int d = g[c];
        if(a != b && b != c && c != d && a == d){
            flag = true;
            break;
        }
    }

    cout << (flag ? "YES\n" : "NO\n");

    return 0;
}