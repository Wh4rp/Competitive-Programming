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

    int n, x, ans = 0; cin >> n >> x;
    int v[n]; rep(i, n) cin >> v[i];
    sort(v, v + n);

    int i = 0, j = n - 1;
    while(i <= j){
        if(v[i] + v[j] <= x)
            i++;
        j--, ans++;
    }
    cout << ans << '\n';

    return 0;
}