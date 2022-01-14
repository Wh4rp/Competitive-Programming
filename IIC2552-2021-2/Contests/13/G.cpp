#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

struct Node {
  ll index, mcd;
};


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  
  int n, s;

  while(cin >> n >> s){

  	vector<ll> c(n + 5);
  	vector<vector<ll>> islands;
  	rep(i, n + 5){
  		vector<ll> aux;
  		islands.push_back(aux);
  	}

  	set<pair<int, int>> sta2;

  	rep_(i, 1, n + 1)
  		cin >> c[i];

  	rep(i, s){
  		ll a, b;
  		cin >> a >> b;
  		islands[a].push_back(b);
  		islands[b].push_back(a);
  	}
  	set<ll> mcd;
  	queue<Node> Q;
  	rep_(i, 1, n + 1){
  		Q.push(Node{i, c[i]});
			sta2.insert({i, c[i]});
			mcd.insert(c[i]);
  	}
  	
  	while(!Q.empty()){
  		Node aux = Q.front();
  		Q.pop();
  		for(ll x : islands[aux.index]){
  			ll mcd1 = __gcd(c[x], aux.mcd);
  			if(!sta2.count({x, mcd1})){
  				Q.push(Node{x, mcd1});
					sta2.insert({x, mcd1});
					mcd.insert(mcd1);
  			}
  		}
  	}
  	cout << mcd.size() << '\n';
  }
  return 0;
}