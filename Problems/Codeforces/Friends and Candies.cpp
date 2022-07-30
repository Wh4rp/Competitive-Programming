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
    int n, sum; cin >> n;
    int v[n]; rep(i, n) cin >> v[i];
    sum = accumulate(v, v + n, 0);
    if(sum % n != 0){
      cout << "-1\n";
    }
    else{
      cout << count_if(v, v + n, 
      [sum, n](int x){return sum < x * n;}) << '\n';
    }
  }
  
  return 0;
}