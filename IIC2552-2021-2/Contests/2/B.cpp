#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep_(i, k, n) for (ll i = k; i < n; ++i)
using ll = long long;

bool sorteo(const pair<int,int> &a,
                   const pair<int,int> &b)
{
       return a.first == b.first ? a.second < b.second : a.first > b.first;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  
  ll t;
  cin >> t;
  while(t--){
  	vector<pair<ll, ll>> rusas;
  	ll n, sol = 0;
  	cin >> n;
  	rep(i, n){
  		ll h, w;
  		cin >> h >> w;
  		rusas.push_back({h, w});
  	}
  	sort(rusas.begin(), rusas.end(), sorteo);
  	multiset<ll> alturas;
  	rep(i, n){
  		// cout << rusas[i].first << ' ' << rusas[i].second << '\n';
  		auto pos = alturas.lower_bound(rusas[i].second + 1);

  		if(pos == alturas.end()){
  			alturas.insert(rusas[i].second);
  			sol++;
  		}

  		else{
  			alturas.erase(pos);
  			alturas.insert(rusas[i].second);
  		}
  	}
  	cout << sol << '\n';
  }
  
  return 0;
}