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

    int n, k, q, l, r;

    cin >> n >> k >> q;
    int a[200005];
    rep(i, 200005) a[i] = 0;
    rep(i, n) {
        cin >> l >> r;
        a[l]++;
        a[r + 1]--;
    }
    rep_(i, 1, 200005) a[i] += a[i - 1];

    // rep_(i, 91, 100){
    //     cout << a[i] << ' ';
    // }
    // cout << '\n';

    rep(i, 200005) {
        if (a[i] >= k)
            a[i] = 1;
        else
            a[i] = 0;
    }

    // rep_(i, 91, 100){
    //     cout << a[i] << ' ';
    // }
    // cout << '\n';

    int b[200005];
    b[0] = 0;

    rep_(i, 1, 200005) b[i] = b[i - 1] + a[i - 1];

    rep(i, q){
        cin >> l >> r;
        cout << b[r+1] - b[l] << '\n';
    }

    return 0;
}