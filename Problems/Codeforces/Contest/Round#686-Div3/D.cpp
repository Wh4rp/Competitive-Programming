#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
 
  vector<bool> is_prime(10000000LL, true);
  is_prime[0] = is_prime[1] = false;
  vector<ll> primes;
  for (ll i = 2; i * i <= 5000000LL; i++) {
      if (is_prime[i]) {
          for (int j = i * i; j <= 5000000LL; j += i)
              is_prime[j] = false;
      } 
  }
  primes.push_back(2LL);
  for(ll i = 3LL; i < 10000000LL; i += 2){
    if(is_prime[i])
      primes.push_back(i);
  }
 
  int t;
  cin >> t;
  while(t--){
    ll n;
    cin >> n;
 
    ll div_mas = 0LL, div_mas_cont = 0LL;
    ll n1 = n;
    for(ll x : primes){
      ll cont_aux = 0LL;
      while(n1 % x == 0LL){
        cont_aux++;
        n1 /= x;
      }
      if(div_mas_cont < cont_aux){
        div_mas = x;
        div_mas_cont = cont_aux;
      }
      if(n1 == 1LL || x * x > n )
        break;
    }
    if(div_mas_cont == 0LL){
      cout << "1\n";
      cout << n << '\n';
    }
    else{
      cout << div_mas_cont << '\n';
      rep(i, div_mas_cont - 1LL){
        cout << div_mas << ' ';
        n /= div_mas;
      }
      cout << n << '\n';
    }
  }
  
  return 0;
}