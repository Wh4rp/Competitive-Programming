#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

vector<ll> segmentedSieve(ll L, ll R) {
    // generate all primes up to sqrt(R)
    ll lim = sqrt(R);
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

ll num1(ll x) {
    return -(x * x * x * x * x * x * x * x);
}

ll num2(ll x, ll y) {
    return -(x * x * y * y);
}

int main() {
    vector<ll> primes = segmentedSieve(1, 4000000000000);

    ll ans = 0, n;

    cin >> n;

    priority_queue<pair<ll, pair<ll, ll>>> numbers;
    numbers.push({num1(primes[0]), {0, -1}});
    numbers.push({num2(primes[0], primes[1]), {0, 1}});

    map<ll, bool> visited;

    while (!numbers.empty()) {
        ll number = numbers.top().first;
        ll a = numbers.top().second.first;
        ll b = numbers.top().second.second;
        numbers.pop();
        if (-number > n)
            continue;
        if(a != b)
            ans++;
        if (b == -1) {
            numbers.push({num1(primes[a + 1]), {a + 1, -1}});
        } else {
            if (-num2(primes[a + 1], primes[b]) <= n &&
                !visited[-num2(primes[a + 1], primes[b])]) {
                visited[-num2(primes[a + 1], primes[b])] = true;
                numbers.push({num2(primes[a + 1], primes[b]), {a + 1, b}});
            }
            if (-num2(primes[a], primes[b + 1]) <= n &&
                !visited[-num2(primes[a], primes[b + 1])]) {
                visited[-num2(primes[a], primes[b + 1])] = true;
                numbers.push({num2(primes[a], primes[b + 1]), {a, b + 1}});
            }
        }
    }

    cout << ans << '\n';

    return 0;
}