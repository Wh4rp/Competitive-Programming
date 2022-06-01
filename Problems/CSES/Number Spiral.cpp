#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

ll diag(ll n){
  return 1 + n * (n - 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  
  int t;
  cin >> t;
  while (t--){
    ll y, x;
    cin >> y >> x;
    // cout << diag(max(y,x)) + abs(x - y) * (min(y, x)%2? -1 : 1) << '\n';
    if(x > y){
      if(y%2){
        cout << diag(max(y,x)) - (x - y) << '\n';
      }
      else{
        cout << diag(max(y,x)) + (x - y) << '\n';
      }
    }
    else{
      if(x%2){
        cout << diag(max(y,x)) - (y - x) << '\n';
      }
      else{
        cout << diag(max(y,x)) + (y - x) << '\n';
      }
    }
  }
  
  return 0;
}
