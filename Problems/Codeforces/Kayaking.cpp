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

    ll n, ans = 0;
    cin >> n;
    ll a[2 * n], b[2 * n];
    rep(i, 2 * n) {
        cin >> a[i];
        ans += a[i];
    }
    sort(a, a + 2 * n);
    rep(i, 2 * n - 1) {
        rep_(j, i + 1, 2 * n) {
            ll aux = 0;
            ll index = 0;
            rep(k, 2 * n) {
                if (k != i && k != j) {
                    b[index] = a[k];
                    index++;
                }
            }
            rep(k, n - 1) {
                aux += abs(b[2 * k] - b[2 * k + 1]);
            }
            ans = min(aux, ans);
        }
    }

    cout << ans << '\n';

    return 0;
}