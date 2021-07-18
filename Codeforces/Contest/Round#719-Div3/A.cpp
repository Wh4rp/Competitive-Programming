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
    bool sol = true;
    int n; cin >> n;
    set<char> s;
    string ss;
    cin >> ss;
    rep(i, n){
      if(s.count(ss[i])){
        cout << "NO\n";
        sol = false;
        break;
      }
      else{
        s.insert(ss[i]);
        int j = i;
        while(ss[i] == ss[j]){
          j++;
        }
        i = j - 1;
      }
    }
    if(sol){
      cout << "YES\n";
    }
  }
  
  return 0;
}