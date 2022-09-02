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
        int n, q;
        cin >> n >> q;
        ll rectangles[1001][1001] = {0};
        rep(i, n) {
            ll h, w;
            cin >> h >> w;
            rectangles[h][w]+= h*w;
        }
        ll prefix[1001][1001] = {0};
        rep(i, 1001)
            rep_(j, 1, 1001)
                prefix[i][j] = rectangles[i][j] + prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1];
        rep(i, q){
            ll ans = 0;
            int hi, wi, hs, ws;
            cin >> hi >> wi >> hs >> ws;
            hi++, wi++, hs--, ws--;
            ans = prefix[hs][ws] - prefix[hs][wi-1] - prefix[hi-1][ws] + prefix[hi-1][wi-1];
            cout << ans << '\n';
        }
    }

    return 0;
}