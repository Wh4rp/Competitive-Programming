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
  
  int t; cin >> t;
  while(t--){
  	ll n, l, r, ans = 0;
  	cin >> n >> l >> r;
	ll v[n]; rep(i, n) cin >> v[i];
   	sort(v, v + n);

   	rep(i, n - 1){
		ans += upper_bound(v + i + 1, v + n, r - v[i]) - v;
		ans -= lower_bound(v + i + 1, v + n, l - v[i]) - v;
   	}
   	cout << ans << '\n';
  }
  
  return 0;
}