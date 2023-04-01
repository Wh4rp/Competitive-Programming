#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

vector<long long> segmentedSieve(long long R) {
    long long lim = sqrt(R);
    vector<char> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
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

    int a, b;
    cin >> a >> b;
    int gcd = __gcd(a, b);
    int copy_gcd = gcd;
    vector<ll> primes = segmentedSieve(gcd), divisors(1, 1);

    for (ll prime : primes) {
        while (copy_gcd % prime == 0) {
            vector<ll> auxs;
            copy_gcd /= prime;
            for (ll divisor : divisors) {
                auxs.push_back(prime * divisor);
            }
            for (ll aux : auxs) {
                divisors.push_back(aux);
            }
        }
    }
    if (copy_gcd != 1) {
        vector<ll> auxs;
        for (ll divisor : divisors) {
            auxs.push_back(copy_gcd * divisor);
        }
        for (ll aux : auxs) {
            divisors.push_back(aux);
        }
    }

    sort(divisors.begin(), divisors.end(), greater<ll>());
    int n;
    cin >> n;
    rep(i, n) {
        int low, high;
        cin >> low >> high;
        ll ans = -1;
        for (ll divisor : divisors) {
            if (low <= divisor && divisor <= high) {
                ans = divisor;
                break;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}