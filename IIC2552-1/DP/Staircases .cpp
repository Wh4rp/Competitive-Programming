#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

ll memo[505][505];

ll DP(ll n, ll h){
  if(n == h)
    return 1;
  
  if(memo[n][h] != -1)
    return memo[n][h];
  
  ll ans = 0;
  
  rep_(i, h + 1, n - h + 1){
    ans += DP(n - h, i);
  }

  return memo[n][h] = ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  
  memset(memo, -1, sizeof(memo));

  ll n, sol = 0; 
  cin >> n;

  rep_(i, 1, n/2 + 1){
    sol += DP(n, i);
  }

  cout << sol << '\n';
  
  return 0;
}