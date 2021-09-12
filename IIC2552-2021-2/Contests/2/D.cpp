#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep_(i, k, n) for (ll i = k; i < n; ++i)
using ll = long long;
void print(multiset<char> xd){
	for(auto x : xd){
		cout << x << ' ';
	}
	cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  string home;
  ll n, N, K = 0, sol = 1000000;
  set<char> tipos;
  vector<int> v(1000, 0);
  cin >> n >> home;

  if( n == 1){
  	cout << "1\n";
  	return 0;
  }
  unordered_map <char, ll> tiposaux;

  rep(i, n){
  	tipos.insert(home[i]);
  }

  ll i = 0;

  N = tipos.size();

  rep_(j, 0, n){
  	if(v[int(home[j])] == 0){
  		K++;
  		v[int(home[j])] = 1;
  		tiposaux.insert({home[j], 1});
  	}
  	else{
  		tiposaux[home[j]]++;
  	}

  	while(tiposaux[home[i]] > 1){
  		tiposaux[home[i]]--;
  		i++;
  	}

  	if(K == N)
  		sol = min(sol, j - i + 1);
  }
  cout << sol << '\n';
  return 0;
}