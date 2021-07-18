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
    ll n, sol = 1e15;
    cin >> n;
    x + x / n es minimo
    for(ll i = 1; i * i <= n; i++){
      if(n % i == 0){
        sol = min(sol, x + x / n - 2);
      }
    }
    cout << sol << '\n';
  }
  return 0;
}