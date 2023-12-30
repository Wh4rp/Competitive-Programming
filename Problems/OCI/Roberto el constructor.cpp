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

    int h, w, m, n;
    cin >> h >> w >> m >> n;

    int a[h][w];

    rep(i, h) rep(j, w) cin >> a[i][j];

    pair<int, int> p[h][w];

    rep(i, w) {
        multiset<int> s;
        rep(j, m) {
            s.insert(a[j][i]);
        }
        p[0][i] = {*s.begin(), *s.rbegin()};

        rep_(j, m, h) {
            s.erase(s.find(a[j - m][i]));
            s.insert(a[j][i]);
            p[j - m + 1][i] = {*s.begin(), *s.rbegin()};
        }
    }

    int ans = 1000000;

    rep(i, h - m + 1) {
        multiset<int> s;
        rep(j, n) {
            s.insert(p[i][j].first);
            s.insert(p[i][j].second);
        }
        ans = min(ans, *s.rbegin() - *s.begin());
        rep_(j, n, w) {
            s.erase(s.find(p[i][j - n].first));
            s.erase(s.find(p[i][j - n].second));
            s.insert(p[i][j].first);
            s.insert(p[i][j].second);
            ans = min(ans, *s.rbegin() - *s.begin());
        }
    }

    cout << ans << '\n';

    return 0;
}