#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep_(i, k, n) for (ll i = k; i < n; ++i)
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    ll n, N, K = 0, i = 0, ans = 1000000;
    string home;
    vector<int> v(125, -1);
    cin >> n >> home;

    rep(i, n){
      if(v[home[i]] == -1){
        K++;
        v[home[i]] = 0;
      }
    }
    
    rep_(j, 0, n){
        K -= (v[home[j]] == 0);
        v[home[j]]++;
        
        while(v[home[i]] > 1){
            v[home[i]]--;
            i++;
        }
        
        if(K == 0)
            ans = min(ans, j - i + 1);
    }
    
    cout << ans << '\n';

    return 0;
}