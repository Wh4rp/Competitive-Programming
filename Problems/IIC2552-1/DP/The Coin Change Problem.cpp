#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;

ll n, m, aux;
ll memo[1000][1000];
vector<int> coins;

ll DP(int i, int c){
  if(c < 0)
    return 0;
  
  if(i == m){
    if(c == 0)
      return 1;
    else
      return 0;
  }

  if(memo[i][c] != -1)
    return memo[i][c];
  
  ll op1 = DP(i, c - coins[i]);
  ll op2 = DP(i + 1, c);

  return memo[i][c] = op1 + op2;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);

  memset(memo, -1, sizeof (memo));

  cin >> n >> m;

  if(n == 0){
    cout << "0\n";
    return 0;
  }
  
  rep(i, m){
    cin >> aux;
    coins.push_back(aux);
  }
  
  cout << DP(0, n) << '\n';

  return 0;
}