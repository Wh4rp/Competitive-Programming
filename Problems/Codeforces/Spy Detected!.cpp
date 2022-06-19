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
    int n, aux;
    cin >> n;
    set<int> s;
    vector<int> v(n);
    rep(i, n){
      cin >> v[i];
      s.insert(v[i]);
    }
    for(auto x : s){
      if(count(v.begin(), v.end(), x) == 1){
        cout << find(v.begin(), v.end(), x) - v.begin() + 1 << '\n';
        break;
      }
    }
  }
  
  return 0;
}