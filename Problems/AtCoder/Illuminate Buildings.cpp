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

    int v[n], ans[n], sol = 1;
    rep(i, n) cin >> v[i];

    for (int i = 1; i < n; i++) {
        rep(j, n) ans[j] = -1;
        rep(j, n) {
            if (j - i >= 0 && v[j - i] == v[j]) {
                ans[j] = ans[j - i] + 1;
            } else {
                ans[j] = 1;
            }
            sol = max(sol, ans[j]);
        }
    }

    cout << sol << '\n';

    return 0;
}