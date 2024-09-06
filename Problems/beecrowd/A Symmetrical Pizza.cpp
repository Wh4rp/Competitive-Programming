#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

ll lcm(ll a, ll b) {
    return a * b / __gcd(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    float x1;
    cin >> x1;

    ll x = (x1 * 100);

    ll y = lcm(36000, x);

    cout << y / x << '\n';

    return 0;
}