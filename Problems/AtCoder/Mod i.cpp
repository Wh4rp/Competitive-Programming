#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

ll v[3005], n;
ll memo[3005][3005];

ll add(ll a, ll b){
  a = a % 1000000007;
  b = b % 1000000007;
  return (a + b) % 1000000007;
}

ll DP(int i, int k){
  if(i == n)
    return 1;
  if(memo[i][k] != -1)
    return memo[i][k];
  else{
    ll sum = 0, ans = 0;
    rep_(j, i, n){
      sum += v[j];
      if(sum % k == 0){
        ans = add(ans, DP(j + 1, k + 1));
      }
    }
    return memo[i][k] = ans;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  
  cin >> n;

  rep(i, n) cin >> v[i];
  memset(memo, -1, sizeof(memo));

  cout << DP(0, 1) << "\n";

  return 0;
}
