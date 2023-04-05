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

    int n, k, q;
    cin >> n >> k >> q;
    int a[k];
    rep(i, k) cin >> a[i];
    rep(i, q) {
        int l;
        cin >> l;
        l--;
        if (l != k - 1 && a[l] + 1 < a[l + 1]) {
            a[l]++;
        } else {
            if (l == k - 1 && a[l] < n) {
                a[l]++;
            }
        }
    }
    rep(i, k) cout << a[i] << " \n"[i == k - 1];

    return 0;
}