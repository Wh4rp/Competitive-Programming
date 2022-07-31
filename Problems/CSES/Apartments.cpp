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

    int n, m, k, ans = 0; cin >> n >> m >> k;
    int a[n], b[m];
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    int i = 0, j = 0;
    while(i < n && j < m){
        if(abs(a[i] - b[j]) <= k)
            i++, j++, ans++;
        else
            b[j] < a[i]? j++ : i++;
    }
    cout << ans << '\n';

    return 0;
}