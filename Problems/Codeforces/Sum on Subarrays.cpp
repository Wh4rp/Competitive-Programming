#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

// -1 -2 -3 ... -30

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> ans(n);
        rep(i, n) ans[i] = - (i + 1);
        int l = -1, r = -1;
        int k1 = k;
        rep(i, n){
            if(k1 >= (n - i)){
                k1 -= (n - i);
            }
            else{
                l = i;
                r = k1;
                break;
            }
        }
        // cout << k1 << ' ' << l << ' ' << r << '\n';
        if(l == -1) {
            if(k1 == 0) {
                l = n - 1;
            }
            else {
                l = 0;
            }
        }
        rep(i, l) {
            ans[i] = 1000;
        }
        if(r != 0) {
            ans[l] = 1;
            rep_(i, l+1, l+r)
                ans[l] -= ans[i];
        }
        rep(i, n)
            cout << ans[i] << ' ';
        cout << '\n';
    }

    return 0;
}