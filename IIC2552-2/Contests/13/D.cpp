// Saque el Euclides op de los apuntes de Pablo

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep_(i, k, n) for (ll i = k; i < n; ++i)
using ll = long long;
ll F[1000005];

void factorial(ll a, ll m){
	ll aux = 1;
	F[0] = 1;
	rep_(i, 1, a + 1){
		aux = (aux * i) % m;
		F[i] = aux;
	}
}

inline ll mod(ll x, ll m) { return ((x %= m) < 0) ? x+m : x; }

ll gcdext(ll a, ll b, ll& x, ll& y) {
  if (a == 0) {
      x = 0, y = 1;
      return b;
  }
  ll x1, y1;
  ll g = gcdext(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return g;
}

ll mulinv(ll a, ll m) {
  ll x, y;
  if (gcdext(a, m, x, y) == 1) return mod(x, m); // make sure 0 <= x < m
  return -1; // no inverse exists
}

bool excel(char a, char b, string num){
	rep(i, num.length()){
		if(num[i] != a && num[i] != b)
			return false;
	}
	return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);

  char char_a, char_b;
  ll a, b, n, sol = 0;

  cin >> char_a >> char_b >> n;
  a = char_a - '0';
  b = char_b - '0';
  factorial(n, 1000000007);

  for(ll sum = b * n, i = 0; i <= n; i++, sum += a - b){
  	if(excel(char_a, char_b, to_string(sum))){
  		ll prod1 = (F[n] * mulinv(F[i], 1000000007)) % (1000000007);
  		ll prod2 = (prod1 * mulinv(F[n - i], 1000000007)) % (1000000007);
  		sol = (sol + prod2) % (1000000007);
  	}
  }
  cout << sol << '\n';
  return 0;
}