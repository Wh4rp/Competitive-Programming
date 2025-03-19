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

    int ans = -1, max = 0, curr_high = 0;
    string s;
    cin >> s;
    rep(i, s.length()) {
        curr_high += (s[i] == '+' ? 1 : -1);
        if(curr_high > max) {
            ans = i + 1;
            max = curr_high;
        }
    }

    cout << ans << '\n';

    return 0;
}