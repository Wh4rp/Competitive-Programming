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
    while (t--){
        int ans = 1000;
        int n;
        cin >> n;
        rep(i, n){
            int x, y;
            cin >> x >> y;
            int k = x;
            while(true) {
                int time_return = x - 1 + (k - x) * 2;
                if(time_return >= (x - 1 + y)) break;
                k++;
            }
            // cout << k << '\n';
            ans = min(ans, k);
        }
        cout << ans - 1 << '\n';
    }

    return 0;
}