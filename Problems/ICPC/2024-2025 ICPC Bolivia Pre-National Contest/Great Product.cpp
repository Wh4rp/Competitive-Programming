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

    ll n, n1;
    cin >> n;
    n1 = n;
    vector<ll> factors;

    for(ll i = 2; i < n; i++){
        while(n1 % i == 0) {
            n1 /= i;
            factors.push_back(i);
        }
    }

    if(n1 == n) {
        factors.push_back(n);
    }

    cout << factors[0];

    rep_(i, 1, factors.size()) {
        ll x = factors[i];
        cout << 'x' << x;
    }

    return 0;
}