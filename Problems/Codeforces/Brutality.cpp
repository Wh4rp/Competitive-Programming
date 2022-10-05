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

    ll n, k, ans = 0;
    string s;
    cin >> n >> k;
    vector<ll> a(n + 1);
    rep(i, n) cin >> a[i];
    cin >> s;
    s += (s[n-1] + 1);
    a[n] = 0;
    vector<int> b;
    rep(i, n + 1){
        b.push_back(a[i]);
        if(s[i] != s[i + 1]){
            sort(b.begin(), b.end(), greater<int>());
            ans += accumulate(b.begin(), b.begin() + min(k, (ll)b.size()), 0LL);
            b.clear();
        }
    }
    cout << ans << '\n';

    return 0;
}