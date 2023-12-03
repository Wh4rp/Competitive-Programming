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
    while(t--){
        int n, k;
        cin >> n >> k;
        int a[n], b[n-1];
        rep(i, n) cin >> a[i];
        rep(i, n - 1) b[i] = abs(a[i] - a[i + 1]);
        sort(b, b + n - 1);
        cout << reduce(b, b + n - k) << '\n';
    }

    return 0;
}