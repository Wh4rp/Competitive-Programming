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
    map<int, int> repi;
    vector<int> v(n);
    rep(i, n){
      cin >> aux;
      if(repi.count(aux) == 0)
        repi.insert({aux, 1});
      else
        repi[aux]++;
      v[i] = aux;
    }
    int sol;
    for(auto [x, y] : repi){
      if(y == 1)
        sol = x;
    }
    rep(i, n){
      if(v[i] == sol)
        cout << i + 1 << '\n';
    }
  }
  
  return 0;
}