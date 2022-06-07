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
  
  int n, m;
  cin >> n >> m;
  int v[m];
  rep(i, m) {
    cin >> v[i];
  }
  sort(v, v + m);
  rep(i, m - 2) {
    if(v[i] + 1 == v[i + 1] && v[i + 1] + 1 == v[i + 2]) {
      cout << "NO\n";
      return 0;
    }
  }
  if(v[0] == 1 || v[m-1] == n){
    cout << "NO\n";
  }
  else{
    cout << "YES\n";
  }
  return 0;
}