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

    int n, x, ans = 0; cin >> n;
    map<int, int> looked;

    rep(i, n){
        cin >> x;
        if(looked.count(x) == 0){
            ans++;
            looked[x] = 1;
        }
    }
    cout << ans << '\n';

    return 0;
}