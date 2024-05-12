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

    ll n, m;
    cin >> n >> m;
    
    if(n%2 == 0) {
        cout << n / 2 * m << '\n';
    }
    else if (m % 2 == 0) {
        cout << m / 2 * n << '\n';
    }
    else {
        ll n1 = n - 1, m1 = m - 1;
        cout << (n1 / 2) * m1 + (m / 2) + (n / 2) << '\n';
    }

    return 0;
}