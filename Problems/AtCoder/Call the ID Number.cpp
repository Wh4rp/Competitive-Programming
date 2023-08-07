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

    int n;
    cin >> n;
    int a[n], called[n];
    rep(i, n) {
        called[i] = 0;
        cin >> a[i];
    }
    rep(i, n) {
        if (called[i] == 0) {
            called[a[i] - 1] = 1;
        }
    }

    cout << count(called, called + n, 0) << '\n';

    rep(i, n) {
        if (called[i] == 0)
            cout << i + 1 << ' ';
    }
    cout << '\n';

    return 0;
}