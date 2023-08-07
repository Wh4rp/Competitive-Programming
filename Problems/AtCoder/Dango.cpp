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
    string s;
    bool flag = true;
    cin >> n >> s;
    int ans = -1, count = 0;
    rep(i, n) {
        if (s[i] == '-') {
            ans = max(ans, count);
            count = 0;
        } else {
            count++;
            flag = false;
        }
    }

    int ans2 = -1, count2 = 0;
    for(int i = n - 1; i >= 0; i--) {
        if (s[i] == '-') {
            ans2 = max(ans2, count2);
            count2 = 0;
        } else {
            count2++;
        }
    }

    if (flag)
        cout << "-1\n";
    else
        cout << max(ans, ans2) << '\n';

    return 0;
}