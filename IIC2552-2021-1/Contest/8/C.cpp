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
  
  int t; 
  cin >> t;
  while(t--){
    string s;
    cin >> s;
    int dos0 = -1, dos1 = s.size();
    for(int i = 0; i < s.size() - 1; ++i){
      if(s[i] == s[i + 1]){
        if(s[i] == '0') dos0 = i;
        else dos1 = min(i, dos1);
      }
    }
    if(dos0 < dos1) cout << "YES\n";
    else cout << "NO\n";
  }
  
  return 0;
}