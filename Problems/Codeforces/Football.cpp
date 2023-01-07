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

    int n, a, b;
    cin >> n >> a >> b;
    vector<int> v(n, 0), w(n, 0);
    int i = 0;
    while (i < n - 1 && a > 0) {
        v[i] = 1;
        a--;
        i++;
    }
    if (b == 0) {
        v[n - 1] += a;
    } else {
        v[0] += a;
        while (i < n - 1 && b > 0) {
            w[i] = 1;
            b--;
            i++;
        }
        w[n - 1] += b;
    }

    int draw_c = 0;

    rep(i, n) {
        if (v[i] == w[i]) {
            draw_c++;
        }
    }
    cout << draw_c << '\n';
    rep(i, n) {
        cout << v[i] << ':' << w[i] << '\n';
    }

    return 0;
}