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

    int n;
    cin >> n;
    map<int, ll> mapa;
    // vecotr<int> mapa(100001, 0);
    rep(i, n) {
        int x;
        cin >> x;
        mapa[x]++;
    }
    vector<ll> v;
    for(auto x : mapa) {
        v.push_back(x.second);
    }
    ll suma = 0;
    rep(i, v.size()) {
        suma += v[i];
    }
    ll ans = 0;
    rep(i, v.size()) {
        ans += v[i] * (suma - v[i]);
        suma -= v[i];
    }
    cout << ans << '\n';

    return 0;
}