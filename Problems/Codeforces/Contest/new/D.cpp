#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  ll n, sum = 0, sol = 0, aux;
  set<ll> s;
  s.insert(0LL);
  cin >> n;
  rep(i, n){
  	cin >> aux;
  	sum += aux;
  	//cout << sum << '\n';
  	if(s.count(sum)){
      //cout << "pas...\n";
  		s = {0, aux};
      sum = aux;
  		sol++;
  	}
  	else{
  		s.insert(sum);
  	}
  }
  cout << sol << '\n';
  
  return 0;
}