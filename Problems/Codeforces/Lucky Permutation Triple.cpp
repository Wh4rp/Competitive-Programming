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
    if (n % 2 == 0) {
        cout << "-1\n";
    } else {
        int curr = n - 1;
        vector<int> a, b, c;

        for (int i = n - 1; i >= 0; i--) {
            a.push_back(i);
            b.push_back((curr - i + 2 * n) % n);
            c.push_back(curr);
            curr = (curr + 1) % n;
        }

        rep(i, n) {
            cout << a[i] << ' ';
        }
        cout << '\n';
        rep(i, n) {
            cout << b[i] << ' ';
        }
        cout << '\n';
        rep(i, n) {
            cout << c[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}