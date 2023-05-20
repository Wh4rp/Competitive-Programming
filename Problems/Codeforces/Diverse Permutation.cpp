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

    int n, k;
    cin >> n >> k;

    int l = 0, i = 1, j = n;

    while (l != n) {
        if (l == k - 1) {
            if (l % 2) {
                rep_(m, i, j + 1) {
                    cout << m << ' ';
                }
            } else {
                for (int m = j; m >= i; m--) {
                    cout << m << ' ';
                }
            }

            break;
        } else {
            if (l % 2) {
                cout << i << ' ';
                i++;
            } else {
                cout << j << ' ';
                j--;
            }
        }

        l++;
    }
    cout << '\n';

    return 0;
}