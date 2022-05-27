#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

ll memo[5005][5005];
string s;
int n, len;

ll DP(int pos, int res){
  if(pos == len)
    return res == 0;
  
  if(memo[pos][res] != -1)
    return memo[pos][res];
  
  if(s[pos] != '?')
    return memo[pos][res] = DP(pos + 1, (res * 10 + s[pos] - '0' + n) % n);
  
  rep_(i, pos == 0, 10){
    s[pos] = '0' + i;
    if(DP(pos + 1, (res * 10 + i) % n))
      return memo[pos][res] = 1;
  }
  s[pos] = '?';
  return memo[pos][res] = 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  
  memset(memo, -1, sizeof(memo));
  
  cin >> s >> n;
  len = s.length();

  if(DP(0, 0))
    cout << s << '\n';
  
  else
    cout << "*\n";

  return 0;
}