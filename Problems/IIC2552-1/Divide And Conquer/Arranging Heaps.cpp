#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

ll memo[1005][1005];
ll n, K;

ll DP(ll i, ll k){
  if (i == n)
    return 0;
  else{
    ll ans = 1;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  
  cin >> n >> K;
  memset(memo, -1, sizeof(memo));

  cout << DP(0, K) << '\n';
  
  return 0;
}