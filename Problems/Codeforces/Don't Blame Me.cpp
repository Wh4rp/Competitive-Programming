#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

const ll MOD = 1e9 + 7;

int bits[128];
int numbers[64];
ll powers[128];

ll bin_pow_2(ll n) {
    ll ans = 1;
    ll base = 2;
    while(n) {
        if(n & 1) ans = (ans * base) % MOD;
        base = (base * base) % MOD;
        n >>= 1;
    }
    return ans;
}

void count_bits(ll i) {
    ll i_copy = i;
    if(i == -1) return;
    int count = 0;
    while(i) {
        if(i & 1) count++;
        i >>= 1;
    }
    bits[i_copy] = count;
    count_bits(i_copy - 1);
}

ll dp[64][10][200];

ll fun(int i, int k, int x) {
    // cout << i << ' ' << k << ' ' << x << '\n';
    if(i == -1) {
        // cout << "bits[" << x << "]: " << bits[x] << '\n';
        if(bits[x] == k) {
            return 1;
        }
        else return 0;
    }
    if(dp[i][k][x] != -1) return dp[i][k][x];
    if(bits[x] < k) return 0;
    ll ans = 0;
    // tomo el numero i
    if(numbers[i] != 0) {
        ll a = (bin_pow_2(numbers[i]) - 1 + MOD) % MOD;
        ans += a * fun(i - 1, k, (x & i));
        ans %= MOD;
    }
    // no tomo el numero i
    ans += fun(i - 1, k, x);

    ans %= MOD;

    return dp[i][k][x] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    count_bits(127);
    
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        memset(numbers, 0, sizeof(numbers));

        rep(i, n) {
            ll x;
            cin >> x;
            numbers[x]++;
        }

        memset(dp, -1, sizeof(dp));

        cout << fun(63, k, 127) << '\n';
    }

    return 0;
}