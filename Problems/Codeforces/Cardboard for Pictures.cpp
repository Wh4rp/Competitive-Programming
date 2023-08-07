#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

int n;
ll c, s[200005];

ll lowerbound() {
    ll i = 0, j = sqrt(c) + 1;

    while (i < j) {
        int m = (i + j) / 2;
        ll used = 0;
        rep(i, n) {
            used += (s[i] + 2 * m) * (s[i] + 2 * m);
            if (used > c)
                break;
        }
        if (used >= c)
            j = m;
        else
            i = m + 1;
    }
    return i;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> c;
        rep(i, n) cin >> s[i];
        cout << lowerbound() << '\n';
    }

    return 0;
}