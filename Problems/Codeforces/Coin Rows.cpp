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
        int m;
        cin >> m;
        ll a[m], b[m], ans = 1e10, accumulateSumA[m], accumulateSumB[m];
        rep(i, m) cin >> a[i];
        rep(i, m) cin >> b[i];
        partial_sum(a, a + m, accumulateSumA);
        partial_sum(b, b + m, accumulateSumB);
        ll scoreA = accumulateSumB[m - 1] + a[m - 1], i = 0;

        rep(i, m) {
            ans = min(ans, max(i > 0 ? accumulateSumB[i - 1] : 0,
                               accumulateSumA[m - 1] - accumulateSumA[i]));
        }

        cout << ans << '\n';
    }

    return 0;
}