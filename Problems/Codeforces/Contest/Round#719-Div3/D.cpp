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
  
  ll t; cin >> t;
  while(t--){
    ll n, cont = 0, aux;
    cin >> n;
    map<ll, ll> repi;
    rep(i, n){
      cin >> aux;
      if(repi.count(aux - i) == 0){
        repi.insert({aux - i, 1});
      }
      else{
        repi[aux - i]++;
      }
    }
    for(auto x : repi){
      cont += x.second * (x.second - 1) / 2;
    }
    cout << cont << '\n';
  }
  
  return 0;
}