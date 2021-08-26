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
  
  ll n;
  while(cin >> n, n){
  	ll sol = 0;
  	stack<pair<ll, ll>> s;
  	rep(i, n){
  		ll aux;
  		cin >> aux;
		  ll mipos = i;
  		while (!s.empty() && s.top().first > aux){
				mipos = min(s.top().second, mipos);
				ll area = (i - s.top().second) * s.top().first;
        s.pop();
				sol = max(sol, area);
  		}
      s.push({aux, mipos});
  	}
  	ll i = n;
  	while (!s.empty()){
      ll area = (i - s.top().second) * s.top().first;
      s.pop();
      sol = max(sol, area);
    }
  	cout << sol << '\n';
  }
  return 0;
}