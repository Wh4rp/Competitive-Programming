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

    int n;
    cin >> n;
    int k = 5 * n, v[k + 5];

    rep(i, k) {
        cin >> v[i];
    }

    sort(v, v + k);

    int ans = accumulate(v + n, v + k - n, 0);

    cout << 1.0 * ans / (3.0 * n)<< '\n';

    return 0;
}