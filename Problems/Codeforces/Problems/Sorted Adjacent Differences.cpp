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
    ll v[n];
    rep(i, n){
      cin >> v[i];
    }
    sort(v, v + n);
    vector<ll>sol;
    if(n%2==1){
      int j = n/2;
      sol.push_back(v[j]);
      rep_(i, 1, j + 1){
        sol.push_back(v[j + i]);
        sol.push_back(v[j - i]);
      }
    }else{
      int j = n/2 - 1;
      rep(i, j + 1){
        sol.push_back(v[j - i]);
        sol.push_back(v[j + 1 + i]);
      }
    }
    
    for(ll x : sol){
      cout << x << ' ';
    }
    cout << '\n';
  }
  return 0;
}