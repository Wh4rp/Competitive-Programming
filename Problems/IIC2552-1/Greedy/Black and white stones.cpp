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
  
  ll a, b, n;
  string s;
  while(cin >> a >> b >> s){
    n = s.size();
    b = a - b;
    ll contb = 0, ans = 0;
    rep(i, n) contb += s[i] == 'B';
    ll i = contb - 1, j = contb;
    while(1){
      while (0 < i && s[i] == 'B')
        i--;
      while (j < n && s[j] == 'W')
        j++;
      if(i < 0 || n <= j)
        break;
      ans += min((j - i) * b, a);
      i--, j++;
    }
    cout << ans << '\n';
  }
  
  return 0;
}