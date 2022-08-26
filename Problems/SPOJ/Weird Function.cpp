#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep_(i, k, n) for (ll i = k; i < n; ++i)
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    ll t, a, b, c, n, ans, fk;
    cin >> t;
    while (t--) {
        ans = 1;
        cin >> a >> b >> c >> n;
        priority_queue<ll> L;
        priority_queue<ll, vector<ll>, greater <ll>> R;
        L.push(1);

        rep_(i, 2, n + 1) {

            fk = (a * L.top() + b * i + c) % 1000000007;
            ans += fk;

            if (i % 2 == 0)
                R.push(fk);
            else
                L.push(fk);

            if (L.top() > R.top()) {
                ll auxL = L.top(), auxR = R.top();
                L.pop();
                R.pop();
                L.push(auxR);
                R.push(auxL);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}