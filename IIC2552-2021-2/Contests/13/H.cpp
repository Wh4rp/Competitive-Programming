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
  
  ll n = 1000005;
  vector<ll> tios;
	vector<bool> is_prime(n+1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= n; i++) {
	    if (is_prime[i]) {
	        for (int j = i * i; j <= n; j += i)
	            is_prime[j] = false;
	    }
	}
 
	rep(i, n){
		if(is_prime[i])
			tios.push_back(i);
	}
	ll N, p;
	cin >> N;
	int cont = 0;
 
	for(auto x : tios){
		if(x > N)
			break;
		if(N % x == 0){
			p = x;
			cont++;
			while(N % x == 0){
				N /= x;
			}
		}
	}
	if(cont == 0){
		cout << N << '\n';
		return 0;
	}
	else{
		if(N != 1)
			cont++;
		
		if(cont == 1)
			cout << p << '\n';
		else
			cout << "1\n";
	}
  return 0;
}