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
    vector<char> t(n, '?');
    rep(i, n) {
        char a = s[i];
        if (k != 0) {
            if ((a - 'a') > ('z' - a)) {
                if (a - 'a' > k) {
                    t[i] = s[i] - k;
                    k = 0;
                } else {
                    t[i] = s[i] + ('a' - a);
                    k += ('a' - a);
                }

            } else {
                if (('z' - a) > k) {
                    t[i] = s[i] + k;
                    k = 0;
                }
                else{
                    t[i] = s[i] + ('z' - a);
                    k -= ('z' - a);
                }
            }
        }
        else{
            t[i] = s[i];
        }
    }

    if (k == 0) {
        for (char c : t)
            cout << c;
        cout << '\n';
    } else
        cout << "-1\n";

    return 0;
}