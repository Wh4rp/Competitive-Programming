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
    if(a + b != n){
      cout << "-1\n";
      continue;
    }
    bool flag = false;
    rep(i, n/2){
      if(s[i] != '?' && s[n - i - 1] != '?' && s[i] != s[n - i - 1]){
        flag = true;
        break;
      }
    }
    if(flag){
      cout << "-1\n";
      continue;
    }
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
    int count_0 = count(s.begin(), s.end(), '0');
    int count_1 = count(s.begin(), s.end(), '1');
    
    if(count_0 > a || count_1 > b){
      cout << "-1\n";
    }
    else{
      rep(i, n / 2){
        if(count_0 >= a - 1)
          break;
        if(s[i] == '?'){
          s[i] = '0';
          s[n-i-1] = '0';
          count_0 += 2;
        }
      }
      rep(i, n / 2){
        if(count_1 >= b - 1)
          break;
        if(s[i] == '?'){
          s[i] = '1';
          s[n-i-1] = '1';
          count_1 += 2;
        }
      }
      if(a - count_0 == 1 && n%2==1){
        s[n/2] = '0';
        count_0++;
      }
      else if(b - count_1 == 1 && n%2==1){
        s[n/2] = '1';
        count_1++;
      }
      if(a == count_0 && b == count_1)
        cout << s << '\n';
      else
        cout << "-1\n";
    }
  }
  
  return 0;
}