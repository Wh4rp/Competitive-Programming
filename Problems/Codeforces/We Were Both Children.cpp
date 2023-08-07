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
        ll trampa[n + 1];
        map<ll, ll> frec;
        rep(i, n + 1) trampa[i] = 0;
        rep(i, n) {
            int x;
            cin >> x;
            frec[x]++;
        }
        for (auto x : frec) {
            for (int i = 1; i * x.first <= n; i++) {
                trampa[i * x.first] += x.second;
            }
        }

        cout << *max_element(trampa, trampa + n + 1) << '\n';
    }

    return 0;
}