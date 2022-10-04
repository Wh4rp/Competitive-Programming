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

    ll n, s;
    cin >> n >> s;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    if(accumulate(a.begin(), a.end(), 0LL) < s)
        cout << -1 << '\n';
    else{
        sort(a.begin(), a.end(), greater<ll>());
        ll count = 0, aux = 0, mini = a[n-1];
        rep(i, n){
            count++;
            s -= (a[i] - mini);
            if(s <= 0){
                break;
            }
        }
        if(s <= 0)
            cout << mini << '\n';
        else
            cout << mini - (s + n - 1) / n << '\n';
    }
    return 0;
}