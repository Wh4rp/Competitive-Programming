#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

ll memo[1000005];

ll DP(int n){
  if(memo[n] != -1) return memo[n];
  else{
    return memo[n] = DP(n / 10) + DP(n % 10);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  
  int a, b;
  cin >> a >> b;
  ll clock[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, sol = 0;

  memset(memo, -1, sizeof memo);
  rep(i, 10){ 
    memo[i] = clock[i];
  }

  rep_(i, a, b + 1){
    sol += DP(i);
  }
  cout << sol << '\n';
  return 0;
}