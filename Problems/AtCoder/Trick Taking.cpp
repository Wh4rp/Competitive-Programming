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

    int n, T;
    bool flag = true;
    cin >> n >> T;
    int c[n], r[n];
    rep(i, n) {
        cin >> c[i];
        if (c[i] == T)
            flag = false;
    }
    if (flag)
        T = c[0];
    rep(i, n) cin >> r[i];
    vector<pair<pair<int, int>, int>> v;
    rep(i, n) v.push_back({{c[i], r[i]}, i});
    sort(v.begin(), v.end(),
         [T](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
             if (a.first.first == T && b.first.first != T)
                 return true;
             if (a.first.first != T && b.first.first == T)
                 return false;
             return a.first.second > b.first.second;
         });

    cout << v[0].second + 1 << '\n';

    return 0;
}