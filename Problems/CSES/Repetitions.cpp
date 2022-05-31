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
  
  string s;
  cin >> s;

  ll n = s.size();
  int maxi = 0, aux = 0;
  char act = ' ';

  rep(i, n){
    if (act != s[i]){
      act = s[i];
      aux = 1;
    }
    else{
      aux++;
    }
    maxi = max(maxi, aux);
  }

  cout << maxi << '\n';
  
  return 0;
}