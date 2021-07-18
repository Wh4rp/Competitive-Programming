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
  while(t--){
    int n, x[2], y[2], k = 0;
    cin >> n;
    string s[n];
    rep(i, n){
      cin >> s[i];
      rep(j, n){
        if(s[i][j] == '*'){
          x[k] = i;
          y[k] = j;
          k++;
        }
      }
    }
    if(x[0] != x[1] && y[0] != y[1]){
      s[x[0]][y[1]] = '*';
      s[x[1]][y[0]] = '*';
    }
    else{
      if(x[0] == x[1]){
        s[(x[0] + 1)%n][y[1]] = '*';
        s[(x[1] + 1)%n][y[0]] = '*';
      }
      else{
        s[x[0]][(y[1] + 1)%n] = '*';
        s[x[1]][(y[0] + 1)%n] = '*';
      }
    }
    rep(i, n){
      cout << s[i] << '\n';
    }
  }
  
  return 0;
}