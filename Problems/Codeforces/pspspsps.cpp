#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

bool contain(int l1, int r1, int l2, int r2){
    if()
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int t;
    cin >> t;
    while (t--){
        int n;
        string s;
        cin >> n >> s;
        bool check = true;

        int a = 0, b = n - 1;
        rep(i, n) {
            int l, r;
            if(s[i] == 'p') {
                l = 0, r = i;
            } else if(s[i] == 's') {
                l = i, r = n-1;
            } else continue;

            cout << a << ' ' << b << '\n';
            cout << l << ' ' << r << '\n';

            if((a <= l && l <= b && b < r) || (l < a && a <= r && r <= b)) {
                check = false;
                break;
            }

            a = max(a, l);
            b = min(b, r);
        }

        if(check) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}