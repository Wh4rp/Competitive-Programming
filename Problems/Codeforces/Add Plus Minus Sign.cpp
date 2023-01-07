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
        int n, count = 1;
        cin >> n;
        string s;
        cin >> s;
        rep(i, n) {
            if (s[i] == '1') {
                count *= -1;
            }
            if (i != 0) {
                if(count == 1){
                    cout << "+-"[count==-1];
                }
                else {
                    cout << '+';
                }
            }
        }
        cout << '\n';
    }

    return 0;
}