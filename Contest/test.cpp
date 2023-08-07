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

    ll n = 0, a = 0, b = 1, c;
    while (a < 1e5) {
        c = a + b;
        a = b;
        b = c;
        n++;
    }

    cout << n << '\n';

    return 0;
}