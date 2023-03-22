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

    int n, k, ans = 0;
    cin >> n >> k;
    int v[n + 5];
    rep(i, n) {
        cin >> v[i];
    }
    sort(v, v + n);

    rep(i, n) {
        if (k == 0) {
            break;
        }
        if (v[i] < 0) {
            v[i] = -v[i];
            k--;
        }
    }

    sort(v, v + n);
    if (k > 0) {
        if (k % 2 == 1){
            v[0] = -v[0];
        }
    }
    rep(i, n){
        ans += v[i];
    }

    cout << ans << '\n';

    return 0;
}