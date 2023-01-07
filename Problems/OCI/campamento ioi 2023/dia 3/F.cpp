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

    int n, w, h;
    cin >> n >> w >> h;
    map<pair<int, int>, int> id;
    vector<pair<int, int>> v(n);
    rep(i, n) {
        cin >> v[i].first >> v[i].second;
        id[v[i]] = i;
    }
    sort(v.begin(), v.end());
    vector<int> dp(n, -1);  

    return 0;
}