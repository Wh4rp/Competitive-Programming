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
  	ll n, l, r, sol = 0;
  	cin >> n >> l >> r;
    
    vector<ll> v(n);

    for(auto& x : v) 
    	cin >> x;

   	sort(v.begin(), v.end());

   	rep_(i, 1, n){
   		if(v[i] < r){
   			int posl = lower_bound(v.begin(), v.begin() + i, max(1LL, l - v[i])) - v.begin();
   			int posr = upper_bound(v.begin(), v.begin() + i, r - v[i]) - v.begin();

   			if(posl != i && v[i] + v[posr - 1] <= r)
   				sol += posr - posl;
   		}
   	}
   	cout << sol << '\n';
  }
  
  return 0;
}