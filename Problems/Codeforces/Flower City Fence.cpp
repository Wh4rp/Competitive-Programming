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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n + 1];
        vector<int> b;
        a[n] = 0;
        rep(i, n) cin >> a[i];

        if (n < a[0]) {
            cout << "NO\n";
        } else {
            int j = 0, level = 0;
            rep(i, n + 1) {
                if (a[j] != a[i]) {
                    rep(k, a[j] - a[i]) {
                        b.push_back(level);
                    }
                    j = i;
                }
                level++;
            }
            if (b.size() < n) {
                cout << "NO\n";
                continue;
            }
            reverse(b.begin(), b.end());
            bool flag = true;
            rep(i, n) {
                if (a[i] != b[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}