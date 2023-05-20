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
    bool distinct_1 = false;
    cin >> n;
    int v[n];
    rep(i, n) {
        cin >> v[i];
        if (v[i] != 1)
            distinct_1 = true;
    }
    if (n == 1) {
        if (v[0] == 1)
            cout << "2\n";
        else
            cout << "1\n";
    } else {
        sort(v, v + n);
        rep(i, n) {
            if (i == 0) {
                cout << 1 << ' ';
            } else {
                if (i == n - 1 && !distinct_1) {
                    cout << 2 << ' ';
                } else {
                    cout << v[i - 1] << ' ';
                }
            }
        }
        cout << '\n';
    }

    return 0;
}