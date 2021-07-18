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
    int n, sum = 0; cin >> n;
    
    vector<int> v(n);
    for(int& x : v){
      cin >> x;
      sum += x;
    }
    if(n == 1){
      cout << "0\n";
      continue;
    }
    if(sum % n != 0){
      cout << "-1\n";
    }
    else{
      int sol = 0;
      for(int& x : v){
        if(sum < x * n)
          sol++;
      }
      cout << sol << "\n";
    }
  }
  
  return 0;
}