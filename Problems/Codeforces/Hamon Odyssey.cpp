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
        int aux = (1 << 31) - 1, ans = 0;
        int a[n];
        rep(i, n) cin >> a[i];
        int i = 0;
        while (i < n) {
            aux &= a[i];
            if (aux == 0) {
                aux = (1 << 31) - 1;
                i++;
                ans++;
            } else
                i++;
        }

        cout << max(1, ans) << '\n';
    }

    return 0;
}