#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

vector<int> primos;
vector<bool> is_prime;

int factorizainador(ll n) {
	int sum = 0;

  for (auto x : primos) {
    if (x > n)
    	break;

    while (n % x == 0){
    	n /= x;
    	sum += x;
    }
    
  }
  if(n != 1){
  	sum += n;
  }
  return sum;
}

ll fun(ll x){
	int aux = factorizainador(x);
	if(aux == x){
		cout << x << ' ';
		return 1;
	}
	else{
		return 1 + fun(aux);
	}
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);

  ll n = 1e5 + 5;
	
	rep(i, n + 1){
		is_prime.push_back(true);
	}
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= n; i++) {
	    if (is_prime[i]) {
	        for (int j = i * i; j <= n; j += i)
	            is_prime[j] = false;
	    }
	}

	rep(i, n){
		if(is_prime[i]){
			primos.push_back(i);
		}
	}

	ll aux; 
	while(cin >> aux, aux != 4){
		int sol = fun(aux);
		cout << sol << '\n';
	}

  return 0;
}