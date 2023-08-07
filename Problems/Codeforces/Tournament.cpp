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

    ll n;
    cin >> n;
    multiset<ll> sums;
    ll v[n];
    int goes_with[n];
    rep(i, n) cin >> v[i];
    sort(v, v + n);
    goes_with[n - 1] = -1;
    for (int i = 0, j = n - 2; i < j; i++, j--) {
        // cout << "Se añade la suma " << v[i] << " + " << v[j] << '\n';
        sums.insert(v[i] + v[j]);
        goes_with[i] = j;
        goes_with[j] = i;
    }

    ll ans = *(sums.rbegin()) - *(sums.begin());
    // cout << ans << '\n';

    for (int i = n - 1; i >= 1; i--) {
        int left = i - 1;
        int par_left = goes_with[left];
        sums.erase(sums.find(v[left] + v[par_left]));
        // cout << "Se quita " << v[left] << " + " << v[par_left] << '\n';

        goes_with[left] = -1;
        goes_with[i] = par_left;
        goes_with[par_left] = i;
        sums.insert(v[i] + v[par_left]);
        // cout << "Se añade " << v[i] << " + " << v[par_left] << '\n';

        ans = min(ans, *(sums.rbegin()) - *(sums.begin()));

        // cout << ans << '\n';
    }

    cout << ans << '\n';

    return 0;
}