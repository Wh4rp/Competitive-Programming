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

    int n, time = 0, water = 0;

    cin >> n;

    rep(i, n) {
        int t, v;
        cin >> t >> v;

        water -= (t - time);
        water = max(water, 0);
        time = t;
        water += v;
    }

    cout << water << '\n';

    return 0;
}