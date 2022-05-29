#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;
// 25
int alpha[27], E[1000005];

vector<int> tios;

int binpow(int a, int b) {
    a %= 10;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % 10;
        a = a * a % 10;
        b >>= 1;
    }
    return res;
}

void factorizainador(int n) {
  for (auto x : tios) {
    if (x > n) 
    	break;

    int y = 0, aux = n;

    while ((aux /= x) > 0){
    	y += aux;
    }

    E[x] = y;
  }
}

void desfactorizainador(int n) {
  for (auto x : tios) {
    if (x > n) 
    	break;

    int y = 0, aux = n;

    while ((aux /= x) > 0){
    	y += aux;
    }

    E[x] -= y;
  }
}

void magic(string word){

	rep(i, 27){
		alpha[i] = 0;
	}
	rep(i, word.length()){
		alpha[word[i] - 97]++;
	}

	factorizainador(word.length());

	rep(i, 26){
		desfactorizainador(alpha[i]);
	}

	int resta = min(E[2], E[5]);

	E[2] -= resta;
	E[5] -= resta;

	int sol = 1;
	
	for (auto x : tios) {
		if(x > word.length())
			break;
    if (E[x] > 0){
    	sol = (sol * binpow(x, E[x])) % 10;
    }
  }

  cout << sol << '\n';

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);

	int n = 1000005;
	vector<bool> is_prime(n+1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= n; i++) {
	    if (is_prime[i]) {
	        for (int j = i * i; j <= n; j += i)
	            is_prime[j] = false;
	    }
	}

	rep(i, n){
		E[i] = 0;
		if(is_prime[i])
			tios.push_back(i);
	}
	
  string word;
  while(cin >> word){
  	magic(word);
  }
  return 0;
}