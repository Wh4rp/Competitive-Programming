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

    int n, r;
    cin >> n >> r;
    rep(i, n) {
        int d, a;
        cin >> d >> a;
        if(d == 1) {
            if(1600 <= r && r <= 2799) {
                r += a;
            }
        } else {
            if(1200 <= r && r <= 2399) {
                r += a;
            }
        }
    }

    cout << r << '\n';

    return 0;
}