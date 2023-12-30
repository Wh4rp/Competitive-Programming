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
        ll v[n];
        rep(i, n) {
            cin >> v[i];
            if (i % 2 == 0)
                v[i] *= -1;
        }
        ll ac = 0;
        set<ll> s = {0};
        bool flag = false;
        rep(i, n) {
            ac += v[i];
            if (s.find(ac) != s.end()) {
                flag = true;
                break;
            }
            s.insert(ac);
        }
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}