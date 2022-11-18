#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

vector<int> primes;

void sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int binpow(int a, int b) {
    a %= 10;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % 10;
        a = a * a % 10;
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    sieve(1000005);

    string word;
    while (cin >> word) {
        int n = word.size();
        vector<int> freq(26, 0), prime_power(1000005, 0);
        rep(i, n) {
            freq[word[i] - 'a']++;
        }

        for (auto prime : primes) {
            if (prime > n)
                break;

            int count = 0, aux = n;

            while ((aux /= prime) > 0) {
                count += aux;
            }

            prime_power[prime] += count;
        }

        rep(i, 26) {
            for (auto prime : primes) {
                if (prime > freq[i])
                    break;

                int count = 0, aux = freq[i];

                while ((aux /= prime) > 0) {
                    count += aux;
                }

                prime_power[prime] -= count;
            }
        }

        int ans = 1;
        int sub = min(prime_power[2], prime_power[5]);
        prime_power[2] -= sub;
        prime_power[5] -= sub;

        for (auto prime : primes) {
            if (prime > n)
                break;
            ans = (ans * binpow(prime, prime_power[prime])) % 10;
        }

        cout << ans << '\n';
    }

    return 0;
}