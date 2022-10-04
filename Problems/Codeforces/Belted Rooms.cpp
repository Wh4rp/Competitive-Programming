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
        int n;
        string s;
        cin >> n >> s;
        int ans = 0, partial = 0, left = 0, right = 0;
        rep(i, n){
            left += s[i] == '<';
            right += s[i] == '>';
            ans += (s[(n+i-1)%n] == '-' || s[i] == '-');
        }
        if(left == 0 || right == 0)
            ans = n;
        cout << ans << '\n';
    }

    return 0;
}