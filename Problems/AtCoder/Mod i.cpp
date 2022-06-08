#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

ll v[3005], n;
ll memo[3005][3005];
ll nextmodule[3005][3005]; // at i by module j
ll sum[3005];

ll add(ll a, ll b){
  a = a % 1000000007;
  b = b % 1000000007;
  return (a + b) % 1000000007;
}

// Do at (i-1)-th with k subsequences

ll DP(int i, int k){
  cout << "DP of " << i << ' ' << k << '\n';
  if(i == n - 1){
    cout << "DING DING " << i << ' ' << k << '\n';
    return 1;
  }
  if(memo[i][k] != -1)
    return memo[i][k];
  else{
    ll ans = 0, next_value = nextmodule[i][k];
    if(next_value != -1){
      ans += DP(next_value, k);
    }
    if(v[i + 1] % (k + 1) == 0){
      ans += DP(i + 1, k + 1);
    }
    else{
      next_value = nextmodule[i + 1][k + 1];
      if(next_value != -1){
        ans += DP(next_value, k + 1);
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

  memset(memo, -1, sizeof(memo));
  memset(nextmodule, -1, sizeof(nextmodule));
  memset(sum, 0, sizeof(sum));

  cin >> n;
  rep(i, n) cin >> v[i];
  rep_(i, 1, n + 1) sum[i] = sum[i - 1] + v[i - 1];
  rep(i, n + 1){
    cout << sum[i] << ' ';
  }
  cout << '\n';
  int antaux[3000];
  rep_(i, 1, n + 1){
    memset(antaux, -1, sizeof(antaux));
    rep_(j, 0, n){
      int module = sum[j + 1] % i;
      if(antaux[module] != -1){
        nextmodule[antaux[module]][i] = j;
      }
      antaux[module] = j;
    }
  }
  rep(i, n){
    cout << nextmodule[i][1] << ' ';
  }
  cout << '\n';
  rep(i, n){
    cout << nextmodule[i][2] << ' ';
  }
  cout << '\n';
  rep(i, n){
    cout << nextmodule[i][3] << ' ';
  }
  cout << '\n';
  // return 0;

  cout << DP(0, 1) << "\n";

  return 0;
}