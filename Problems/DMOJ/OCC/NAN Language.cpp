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
        string s;
        cin >> s;
        int n = s.size();
        bool flag = false;
        rep(i, n - 1) {
            if (s[i] == 'N' && s[i + 1] == 'N') {
                flag = true;
                break;
            }
        }
        if (flag || s == "A") {
            cout << "0 0\n";
        } else {
            if(s[0] == 'A')
                cout << "0 1\n";
            else
                cout << "1 1\n";
        }
        continue;
    }

    return 0;
}