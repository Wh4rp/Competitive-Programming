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

    ll n, a, b;
    cin >> n >> a >> b;
    ll d[n];
    rep(i, n){
        cin >> d[i];
        d[i] = d[i] % (a + b);
    }

    sort(d, d + n);

    ll rango = d[n-1] - d[0] + 1;

    rep(i, n - 1){
        ll x = d[i];
        ll y = d[i + 1];
        rango = min(rango, x + (a + b) - y + 1);
    }

    // cout << "rango " << rango << '\n';

    if(rango <= a){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }


    return 0;
}