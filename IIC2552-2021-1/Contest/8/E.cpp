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
  	vector<ll> v(n);
  	for(ll& x : v)
  		cin >> x;
  	ll sol = 0, com = 0, com1 = 0;
  	for(ll& x : v){
  		if(x < 0){
  			sol += com;
  			com = 0;
  			com1 = (com1 == 0) ? x : max(x, com1);
  		}
  		else{
  			com = max(x, com);
  			sol += com1;
  			com1 = 0;
  		}
  	}
  	sol += com;
  	sol += com1;
  	cout << sol << '\n';
  }
  
  return 0;
}