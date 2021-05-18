#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  
  int t, a, b, k, l; 
  cin >> t; 
  rep(i, t){
    cin >> a >> b;
    if(a < b) swap(a, b);
    a = min(a, 2 * b);
    k = (2 * a - b) / 3, l = (2 * b - a) / 3;
    if(k < 0 || l < 0) cout << "0\n";
    else cout << k + l + ((a + b) % 3 == 1) << '\n';
  }
  
  return 0;
}