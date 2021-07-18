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
  
  ll n;
  while(cin >> n, n != 0){
  	ll sol = 0;
  	rep(i, n){
  		sol += (n - i) * (2 * i + 1);
  	}
  	cout << sol << '\n';
  }
  
  return 0;
}