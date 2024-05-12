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

    ll integer_with_radius_r[100005];
    ll ans[100005];
    ans[0] = 0;
    rep(i, 100005){
        integer_with_radius_r[i] = 0;
    }
    for(ll i = 1; i < 100005; i++){
        for(ll j = i + 1; (i * i) + (j * j) < 100005; j++){
            integer_with_radius_r[(i * i) + (j * j)]++;
        }
    }

    // cout << integer_with_radius_r[5] << '\n'; // Output: 1

    int k = 1, c = 1;
    while(k < 100005){
        ans[k] = (k - 1 - integer_with_radius_r[k+1]) * 8 + 4;
        k++;
    }

    ll p = 1;
    k = 1;
    while(2 * p * p < 100005){
        while(!(k*k <= 2 * p * p && 2 * p * p < (k+1)*(k+1))){
            k++;
        }
        ans[k] += 4;
        p++;
    }

    int t;
    cin >> t;
    while(t--){
        ll r;
        cin >> r;
        cout << ans[r] << '\n';
    }

    return 0;
}