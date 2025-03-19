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

    ll n, s, total = 0;
    set<ll> sums_set = {0};
    cin >> n >> s;
    ll sums[n], a[n];
    rep(i, n) cin >> a[i];
    sums[0] = a[0];
    sums_set.insert(sums[0]);
    rep_(i, 1, n) {
        sums[i] = a[i] + sums[i-1];
        sums_set.insert(sums[i]);
    }
    total = sums[n - 1];

    int cont = 0;

    while(s > 0) {
        bool ans = false;
        if (sums_set.count(s))
            ans = true;

        rep(i, n) {
            ll sum_aux = total - sums[i];
            if (sums_set.count(s - sum_aux))
                ans = true;
        }
        if(ans) {
            cout << "Yes\n";
            return 0;
        }
        cont++;
        if(cont == 1) s = (s % total) + total;
        else s -= total;
    }

    cout << "No\n";

    return 0;
}