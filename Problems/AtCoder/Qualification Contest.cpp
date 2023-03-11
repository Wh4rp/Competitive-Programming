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

    int n, k;
    cin >> n >> k;
    string names[k];
    rep(i, k){
        cin >> names[i];
    }
    sort(names, names + k);
    rep(i, k){
        cout << names[i] << '\n';
    }

    return 0;
}