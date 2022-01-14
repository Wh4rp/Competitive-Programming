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
    int a, b, c;
    cin >> a >> b >> c;
    if(a + b == c || a + c == b || b + c == a){
    	cout << "YES\n";
    	continue;
    }
    if((a == b && c % 2 == 0) || (a == c && b % 2 == 0) || (b == c && a % 2 == 0)){
    	cout << "YES\n";
    	continue;
    }
    cout << "NO\n";
  }
  
  return 0;
}