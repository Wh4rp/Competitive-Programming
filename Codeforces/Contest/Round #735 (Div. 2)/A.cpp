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
    ll n, maxi = 0LL;
    cin >> n;
    vector<ll> v(n);
    for(ll& x : v)
    	cin >> x;
    rep(i, n - 1){
    	maxi = max(v[i] * v[i + 1], maxi);
    }
    cout << maxi << '\n';
  }
  
  return 0;
}