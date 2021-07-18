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
  
  int t;
  cin >> t;
  while(t--){
    ll n;
    cin >> n;
    map<ll, ll> ocur;
    vector<ll> v(n);
    for(ll& x : v)
      cin >> x;
    rep(i, n - 1){
      if(ocur.count(v[i]) == 0)
        ocur.insert({v[i], 2});
      else if(v[i] != v[i+1]){
        ocur[v[i]]++;
      }
    }
    if(n > 1){
      if(ocur.count(v[n - 1]) == 0)
        ocur.insert({v[n - 1], 2});
      else if(v[n - 1] != v[n - 2]){
        ocur[v[n - 1]]++;
      }
    }
    
    ocur[v[0]]--;
    ocur[v[n - 1]]--;
    ll mini = 2*1e5;
    for(auto [x, y] : ocur){
      cout << x << ' ' << y << '\n';
      mini = min(mini, y);
    }
    cout << max(0LL, mini) << '\n';
  }
  
  return 0;
}