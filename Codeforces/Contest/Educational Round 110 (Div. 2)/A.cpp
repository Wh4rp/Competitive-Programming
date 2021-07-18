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
  	int v[4];
  	cin >> v[0] >> v[1] >> v[2] >> v[3];
  	int win1 = max(v[0], v[1]);
  	int win2 = max(v[2], v[3]);
  	sort(v, v + 4);
  	if(win1 > win2) swap(win1, win2);
  	if(v[2] == win1) cout << "YES\n";
  	else cout << "NO\n";

  }
  
  return 0;
}