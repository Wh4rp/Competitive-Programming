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

  ll n, q, maxi = 0;
  
  deque<ll> d;

  cin >> n >> q;

  ll sol[n][2];

  rep(i, n){
  	ll aux;
  	cin >> aux;
  	maxi = max(maxi, aux);
  	d.push_back(aux);
  }
  ll x, y, j = 1;
  do{
  	x = d[0], y = d[1];
  	sol[j][0] = x, sol[j][1] = y;

  	d.pop_front();
  	d.pop_front();
  	d.push_front(max(x, y));
  	d.push_back(min(x, y));
  	j += 1;
  }while(max(x, y) != maxi);

  while(q--){
  	ll aux;
  	cin >> aux;

  	if(aux < j)
  		cout << sol[aux][0] << " " << sol[aux][1] << '\n';
  	else{
  		cout << d[0] << " " << d[((aux - j) % (n - 1)) + 1] << '\n';
  	}
  }
  
  return 0;
}