#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

ll ans(ll n) {
    vector<char> is_prime(n + 2, true);
    ll count = 0;
    for (ll i = 2; i <= n; i++) {
        if (is_prime[i]) {
            count += (n / i);
            for (ll j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }

    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << ans(n) << '\n';
    }

    return 0;
}