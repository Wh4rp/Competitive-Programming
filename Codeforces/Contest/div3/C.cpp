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
    bool sol = true;
    int a, b;
    string s;
    cin >> a >> b >> s;
    map<char, int> cont;
 
    cont.insert({'0', 0});
    cont.insert({'1', 0});
    cont.insert({'?', 0});
 
    int n = a + b;
    if((a%2 == 1 || b%2 == 1) && n%2 == 0){
      cout << "-1\n";
      continue;
    }
    int l = 0, r = n - 1;
    while (l < r){
      if(s[l] == s[r]){
        cont[s[l]] += 2;
      }
      else{
        if(s[l] != '?' && s[r] != '?'){
          sol = false;
          break;
        }
        else{
          if(s[l] != '?')
            s[r] = s[l];
          else
            s[l] = s[r];
          cont[s[l]] += 2;
        }
      }
      l++, r--;
    }
 
    
 
    if(n % 2 == 1)
      cont[s[r]] += 1;
 
    if(cont['0'] > a || cont['1'] > b){
      sol = false;
    }
    if(sol == false){
      cout << "-1\n";
      continue;
    }
 
    l = 0, r = n - 1;
    while (l < r){
      if(s[l] == '?'){
        if(cont['0'] < a - 1){
          s[l] = '0';
          s[r] = '0';
          cont['0'] += 2;
          cont['?'] -= 2;
        }
        else{
          s[l] = '1';
          s[r] = '1';
          cont['1'] += 2;
          cont['?'] -= 2;
        }
      }
      l++, r--;
    }
    if(n % 2 == 1){
      if(s[r] == '?'){
        if(cont['0'] < a){
          s[l] = '0';
          s[r] = '0';
          cont['0'] += 1;
          cont['?'] -= 1;
        }
        else{
          s[l] = s[r] = '1';
          cont['1'] += 1;
          cont['?'] -= 1;
        }      
      }
 
    }
    if(cont['?'] != 0 || (cont['0'] != a && cont['1'] != b)){
      cout << "-1\n";
    }
    else{
      cout << s << '\n';
    }
 
  }
  
  return 0;
}