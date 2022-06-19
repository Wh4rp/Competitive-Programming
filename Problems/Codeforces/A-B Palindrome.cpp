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
  while (t--){
    int a, b;
    string s;
    cin >> a >> b >> s;
    int n = s.size();
    rep(i, n/2){
      if(s[i] != s[n-i-1]){
        if(s[i] == '?' && s[n-i-1] != '?'){
          s[i] = s[n-i-1];
        }
        if(s[i] != '?' && s[n-i-1] == '?'){
          s[n-i-1] = s[i];
        }
      }
    }
    a -= count(s.begin(), s.end(), '0');
    b -= count(s.begin(), s.end(), '1');
    rep(i, n){
      if(s[i] == '?'){
        int limit = i != n-i-1? 1 : 0;
        if(a > limit){
            s[i] = s[n-i-1] = '0';
            a-= limit + 1;
          }
        else if(b > limit){
          s[i] = s[n-i-1] = '1';
          b -= limit + 1;
        }
      }
    }
    string v = s;
    reverse(v.begin(), v.end());
    if(v != s || a || b)
      cout << "-1\n";
    else
      cout << s << '\n';
  }
  
  return 0;
}