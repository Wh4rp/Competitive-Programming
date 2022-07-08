#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;
  
int len(int a, int b, int n){
  return n + a - b;
}
  
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
    map<int, vector<int>> pos;
    rep(i, n){
      cin >> aux;
      if(pos.find(aux) == pos.end())
        pos.insert({aux, vector<int>{i}});
      else
        pos[aux].push_back(i);
    }
    int ans = -1;
    for(auto p : pos){
      auto v = p.second;
      if (v.size() == 1)
        continue;
      else{
        int m = v.size();
        for(int i = 0; i < m - 1; i++){
          ans = max(ans, len(v[i], v[i + 1], n));
        }
      }
    }
    cout << ans << '\n';
  }
  
  return 0;
}