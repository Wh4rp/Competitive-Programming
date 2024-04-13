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
    while(t--){
        int n;
        cin >> n;
        ll v[n], ans = 1;
        rep(i, n) cin >> v[i];
        sort(v, v + n);
        v[0]++;
        rep(i, n) ans *= v[i];
        cout << ans << '\n';
    }

    return 0;
}