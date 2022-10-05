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

    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        int n = s.length();
        int l = 0, r = 0, u = 0, d = 0;
        rep(i, n) {
            if (s[i] == 'L') l++;
            if (s[i] == 'R') r++;
            if (s[i] == 'U') u++;
            if (s[i] == 'D') d++;
        }
        l = min(l, r), d = min(d, u);
        if(l == 0)
            d = min(d, 1);
        if(d == 0)
            l = min(l, 1);
        if((l != 0 && d != 0) || (l == 1 && d == 0) || (l == 0 && d == 1)){
            cout << 2 * (l + d) << '\n';
            rep(i, l)
                cout << 'L';
            rep(i, d)
                cout << 'D';
            rep(i, l)
                cout << 'R';
            rep(i, d)
                cout << 'U';
            cout << '\n';
        }
        else{
            cout << "0\n\n";
        }
    }

    return 0;
}