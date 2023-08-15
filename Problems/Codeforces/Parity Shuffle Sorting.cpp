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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int v[n];
        rep(i, n) cin >> v[i];
        int main_pair = v[0] % 2, last_pos = -1;
        vector<pair<int, int>> ans;
        for (int i = n - 1; i >= 0; i--) {
            if (last_pos == -1 && v[i] % 2 == main_pair) {
                last_pos = i;
            } else if (v[i] % 2 == main_pair) {
                ans.push_back({i, last_pos});
            }
        }
        rep(i, n) {
            if (v[i] % 2 != main_pair) {
                ans.push_back({0, i});
            }
        }
        cout << ans.size() << '\n';
        for (auto x : ans)
            cout << x.first + 1 << ' ' << x.second + 1 << '\n';
    }

    return 0;
}