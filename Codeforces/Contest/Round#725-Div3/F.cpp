#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

ll f(ll x){
	ll cont = 0;
	while(x){
		cont += x;
		x /= 10;
	}
	return cont;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  
  ll t;
  cin >> t;
  while(t--){
  	ll l, r;
  	cin >> l >> r;
  	cout << f(r) - f(l) << '\n';
  }
  
  return 0;
}