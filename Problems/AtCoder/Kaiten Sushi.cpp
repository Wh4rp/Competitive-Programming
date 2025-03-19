#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

int mini[200005];

int bs(int n, int key) {
    int i = 0, j = n - 1;
    while (i < j) {
        int m = (i + j) / 2;
        if (mini[m] <= key)
            j = m;
        else
            i = m + 1;
    }
    if(mini[i] > key) return -1;
    return i + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int n, m;
    cin >> n >> m;

    int a[n], b[m];

    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    mini[0] = a[0];

    rep_(i, 1, n){
        mini[i] = min(mini[i-1], a[i]);
    }

    rep(i, m) {
        cout << bs(n, b[i]) << '\n';
    }

    return 0;
}