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

    map<ll, map<ll, ll>> points_x, points_y;

    // points_x[0] -> la frecuencia de los puntos que estan en el eje x = 0//
    //  //
    int n;
    cin >> n;
    rep(i, n) {
        ll x, y;
        cin >> x >> y;
        points_x[x][y] += 1;
        points_y[y][x] += 1;
    }

    ll ans = 0, repetidos = 0;

    for(auto x : points_x){
        ll len = 0;
        for(auto y : x.second){
            if(y.second > 1 && points_y[y.first][x.first]){
                repetidos += ((y.second)*(y.second - 1)) / 2;
            }
            len += y.second;
        }
        ans += (len * (len - 1)) / 2;
    }

    for(auto y : points_y){
        ll len = 0;
        for(auto x : y.second){
            len += x.second;
        }
        ans += (len * (len - 1)) / 2;
    }

    ans -= repetidos;

    cout << ans << '\n';

    return 0;
}