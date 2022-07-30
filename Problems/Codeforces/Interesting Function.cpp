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
  
  ll t;
  cin >> t;
  while(t--){
  	ll l, r, ans = 0;
  	cin >> l >> r;
    while(l || r){
      ans += r - l;
      l /= 10;
      r /= 10;
    }
  	cout << ans << '\n';
  }
  
  return 0;
}