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
        int n, len = 0;
        cin >> n;

        vector<int> v;
        rep(i, n) {
            int x;
            cin >> x;
            if (len == 0 || (x != v[len - 1])) {
                v.push_back(x);
                len++;
            }
        }

        int ans = 0;
        
        if(len == 1) {
            cout << 1 << '\n';
            continue;
        }

        rep(i, len) {
            if(i == 0) {
                if(v[i] > v[i + 1]) {
                    ans++;
                }
            } else if(i == len - 1) {
                if(v[i] > v[i - 1]) {
                    ans++;
                }
            } else {
                if(v[i] > v[i - 1] && v[i] > v[i + 1]) {
                    ans++;
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}