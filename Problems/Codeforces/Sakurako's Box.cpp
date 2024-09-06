#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

const int N = 1e9 + 7;

// Calculate inverse of a mod N
ll inv(ll a){
    ll res = 1, b = N-2;
    while(b){
        if(b & 1) res = (res * a) % N;
        a = (a * a) % N;
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll a[n];
        rep(i, n) cin >> a[i];

        ll P = 0, sum = a[n-1];

        for(int i = n-2; i >= 0; --i){
            P += a[i] * sum;
            sum += a[i];
            P %= N;
            sum %= N;
        }

        ll Q = (n * (n - 1)) / 2;
        Q %= N;
        ll invQ = inv(Q);

        cout << (P * invQ) % N << '\n';

    }

    return 0;
}