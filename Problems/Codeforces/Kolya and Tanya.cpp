#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1000000007;

ll binpow(ll a, ll b) {
  return b ? (binpow(a * a % MOD, b >> 1) * (b & 1 ? a : 1)) % MOD : 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  
  ll n;
  cin >> n;
  ll x = binpow(27, n), y = binpow(7, n);
  cout << (MOD + x - y) % MOD << '\n';
  
  return 0;
}