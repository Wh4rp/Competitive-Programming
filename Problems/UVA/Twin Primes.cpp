#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

vector<pair<ll, ll>> segmentedSieve(ll R) {
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

    vector<pair<ll, ll>> twins;

    rep(i, primes.size() - 1) {
        if (primes[i + 1] - primes[i] == 2)
            twins.push_back({primes[i], primes[i + 1]});
    }

    return twins;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    vector<pair<ll, ll>> twins = segmentedSieve(20000000);
    int n;
    while (cin >> n) {
        cout << "(" << twins[n - 1].first << ", " << twins[n - 1].second
             << ")\n";
    }

    return 0;
}