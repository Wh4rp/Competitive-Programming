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
        int n, k;
        cin >> n >> k;
        int a[n];
        rep(i, n) cin >> a[i];
        int add_positions[n];
        rep(i, n) add_positions[i] = a[i] - (i + 1);
        ll pos_init = 0, curr_add_pos = 0;
        rep(i, k) {
            while (curr_add_pos < n &&
                   add_positions[curr_add_pos] <= pos_init) {
                                curr_add_pos++;
            }
            pos_init += curr_add_pos;
        }
        cout << pos_init + 1 << '\n';
    }

    return 0;
}