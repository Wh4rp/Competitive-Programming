#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

vector<ll> segmentedSieve(ll R) {
    // generate all primes up to sqrt(R)
    ll lim = R;
    vector<char> mark(lim + 1, false);
    vector<ll> primes;
    for (ll i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (ll j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }
    return primes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    ll n, ans = 1;

    cin >> n;

    vector<ll> primes = segmentedSieve(1000000);

    for (ll x : primes) {
        if (n % x == 0) {
            ans *= x;
            while (n % x == 0) {
                n /= x;
            }
        }
        if (n == 1)
            break;
    }

    cout << ans * n << '\n';

    return 0;
}