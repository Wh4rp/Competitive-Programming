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

    int x;
    cin >> x;
    int count = 0;
    rep_(i, 1, 10) rep_(j, 1, 10) {
        if(i * j == x) {
            count++;
        }
    }

    cout << 2025 - count * x << '\n';

    return 0;
}