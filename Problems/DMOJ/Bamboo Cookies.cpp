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

    int n, ans = 0;
    cin >> n;
    int a[n];
    rep(i, n) cin >> a[i];
    rep(i, n) {
        if (a[i] == -1)
            continue;
        rep_(j, i + 1,  n){
            if (a[j] == -1)
                continue;
            if ((a[i] + a[j]) % 2 == 0) {
                a[i] = -1;
                a[j] = -1;
                ans++;
                break;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}