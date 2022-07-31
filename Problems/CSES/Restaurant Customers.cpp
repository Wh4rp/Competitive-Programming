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

    int n, ans = 0, now = 0; cin >> n;
    vector<pair<int, int>> events(2*n);
    rep(i, n) {
        int s, e; cin >> s >> e;
        events[2*i] = {s, 1};
        events[2*i+1] = {e, -1};
    }
    sort(events.begin(), events.end());
    rep(i, 2*n) {
        now += events[i].second, ans = max(ans, now);
    }
    cout << ans << '\n';

    return 0;
}