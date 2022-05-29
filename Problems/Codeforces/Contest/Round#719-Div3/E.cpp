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
    ll n, m = 0, sol = 0;
    string s;
    cin >> n >> s;
    rep(i, n){
      if(s[i] == '*')
        m++;
    }
 
    ll cont = 0, i = 0;
 
    while(i < n && cont <= m / 2){
      if(s[i] == '*'){
        cont++;
      }
      else{
        sol += cont;
      }
      i++;
    }
    if(i != n){
      int j = n - 1, cont1 = 0;
      while(j >= i && j >= 0 && (cont1 + cont) <= m){
        if(s[j] == '*'){
          cont1++;
        }
        else{
          sol += cont1;
        }
        j--;
      }
    }
    cout << sol << '\n';
  }
  
  return 0;
}