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

    ll ans[200005];

    ans[0] = 1;
    ans[1] = 3;

    rep_(i, 2, 200005){
        ans[i] = ans[i-1] + 1;
        if((3 * ans[i]) % (ans[i-1] + ans[i-1]) == 0)
            ans[i]++;
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        rep(i, n){
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}