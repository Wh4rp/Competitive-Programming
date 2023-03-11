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
    string s;
    cin >> n >> k >> s;
    rep(i, n) {
        if (s[i] == 'o') {
            if (k) {
                k--;
            } else {
                s[i] = 'x';
            }
        }
    }
    cout << s << '\n';

    return 0;
}