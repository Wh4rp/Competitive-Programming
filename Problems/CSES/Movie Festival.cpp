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

    int n; cin >> n;
    vector<pair<int, int>> movies(n);
    rep(i, n) {
        int s, e; cin >> s >> e;
        movies[i] = {s, e};
    }
    sort(movies.begin(), movies.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });
    int ans = 0, last = -1;
    for(auto& m: movies) {
        if (m.first >= last)
            ans++, last = m.second;
    }
    cout << ans << '\n';

    return 0;
}