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

    ll ans = 0, L = 0;
    string s;
    cin >> s;
    int n = s.length();
    rep(i, n - 3) {
        if (s[i] == 'b' && s[i + 1] == 'e' && s[i + 2] == 'a' &&
            s[i + 3] == 'r') {
            ans += (n - (i + 4) + 1) * (i - L + 1);
            L = i + 1;
        }
    }

    cout << ans << '\n';

    return 0;
}