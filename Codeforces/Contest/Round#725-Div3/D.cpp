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

  vector<ll> primes;
	vector<char> is_prime(1e9 + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (ll i = 2; i * i <= 1e9 + 1; i++) {
    if (is_prime[i]) {
      for (ll j = i * i; j <= 1e9 + 1; j += i)
        is_prime[j] = false;
      primes.push_back(i);
    }
	}

  int t;
  cin >> t;
  while (t--){
  	ll a, b, k;
  	cin >> a >> b >> k;
  	ll a1 = a, b1 = b, conta = 0, contb = 0;
  	if(is_prime[a] && a > 1){
  		conta = 1;
  	}
  	else{
  		if(a == 1)
  			conta = 0;
  		else{
  			for (auto x : primes) {
			    while(a1 % x == 0){
			    	a1 /= x;
			    	conta++;
			    }
			    if(a1 == 1)
			    	break;
				}
  		}
  	}

  	if(is_prime[b] && b > 1){
  		contb = 1;
  	}
  	else{
  		if(b == 1)
  			contb = 0;
  		else{
  			for (auto x : primes) {
			    while(b1 % x == 0){
			    	b1 /= x;
			    	contb++;
			    }
			    if(b1 == 1)
			    	break;
				}
  		}
  	}
  	
  	ll mini;

  	if(a == b)
  		mini = 0;
  	else{
  		if(a == 1 || b == 1) mini = 1;
  		else{
  			if(a % b == 0 || b % a == 0)
  				mini = 1;
  			else
  				mini = 2; 
  		}
  	}

  	ll maxi = contb + conta;
		if(mini <= k && k <= maxi)
			cout << "YES\n";
		else
			cout << "NO\n";
  }
  
  return 0;
}