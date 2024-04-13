#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

// i.e. "first element >= key"

int lowerbound(vector<ll>& a, int key) {
    int  i = 0, j = a.size() - 1;

    while (i < j) {
        int m = (i + j) / 2;
        assert(0 <= m && m < a.size());
        if (a[m] >= key)
            j = m;
        else
            i = m + 1;
    }
    if(a[i] < key)
        return i;
    else if(i > 0 && a[i-1] < key)
        return i-1;
    else
        return i;
}

ll op(ll n){
    // cout << "op(" << n << ")\n";
    return (n * (n - 1)) / 2 + n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int t, j = 0;
    cin >> t;

    while(t--){
        j++;
        int n, m;
        cin >> n >> m;
        // if(j <= 8){
        //     cout << n << ' ' << m << '\n';
        //     if(j==8)
        //         return 0;
        // }
        vector<vector<ll>> incompatibilidades(n+5, vector<ll>());
        
        rep(i, m){
            ll x, y;
            cin >> x >> y;
            incompatibilidades[x].push_back(y);
            incompatibilidades[y].push_back(x);
        }
        rep_(i, 1, n+1){
            sort(incompatibilidades[i].begin(), incompatibilidades[i].end());
        }

        ll ans = 0;
        
        ll l = 1, r = 1;

        while(r < n){
            r++;
            if(incompatibilidades[r].size() > 0){
                // cout << "Buscaremos " << l << " en el vector de incompatibilidades de " << r << '\n';
                int k = lowerbound(incompatibilidades[r], r);
                if(l <= incompatibilidades[r][k] && incompatibilidades[r][k] < r){
                    ll largo = incompatibilidades[r][k] - l + 1;
                    ans += op(largo);
                    ans += largo * (r - (incompatibilidades[r][k] + 1));
                    l = incompatibilidades[r][k] + 1;
                }
                else{
                    // cout << "No se halló incompatibilidad en el rango " << l << " ... " << r << '\n';
                }
            }
            // cout << l << " ... " << r << '\n';
        }

        ans += op(r - l + 1);

        cout << ans << '\n';
    }


    return 0;
}