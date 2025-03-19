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

    string s;
    cin >> s;

    int i = 0, ans = 0, n = s.length();

    while (i < n) {
        if (i < n - 1) {
            if (s[i] == '0' && s[i + 1] == '0')
                i += 2;
            else
                i++;
        } else
            i++;
        ans++;
    }

    cout << ans << '\n';

    return 0;
}