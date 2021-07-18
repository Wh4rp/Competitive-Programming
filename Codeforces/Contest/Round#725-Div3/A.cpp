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
    int n; cin >> n;
    vector<int> v(n);
    for(auto& x : v)
      cin >> x;
    int mini = find (v.begin(), v.end(), 1) - v.begin() + 1;
    int maxi = find (v.begin(), v.end(), n) - v.begin() + 1;
    int a = min(mini, maxi), b = max(mini, maxi);
    
    cout << min(n - a + 1, min(b, a + n - b + 1)) << "\n";
    
    // cout << n - a + 1 << "\n";
    // cout << b << "\n";
    // cout << a + n - b + 1 << "\n";\
    
  }
  
  return 0;
}