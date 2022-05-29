#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

const int mod = 1000000007;

ll memo[5005][5005];

ll DP(ll n, ll m){
	if(n < 0 || m <= 0)
		return 0;
	if(n == 0 || m == 1)
		return 1;

	if(memo[n][m] != -1)
		return memo[n][m];

	ll ans = 0;
	ans += DP(n - m, m) % mod;
	ans += 2 * DP(n, m - 1) % mod;
	ans -= DP(n, m - 2) % mod;
	
	return memo[n][m] = (ans + mod) % mod;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  
  memset(memo, -1, sizeof(memo));
  
	ll s, b;
	cin >> s >> b;
	cout << DP(b - s, s) << '\n';
	
  return 0;
}