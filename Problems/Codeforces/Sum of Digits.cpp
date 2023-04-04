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
    if (s.size() == 1) {
        cout << "0\n";
    } else {
        ll n = 0;
        int ans = 1;
        rep(i, s.size()) n += s[i] - '0';
        while(n >= 10){
            int m = 0;
            while(n){
                m += n % 10;
                n /= 10;
            }
            n = m;
            ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}