#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define REP(i,k,n) for (i = k; i <= n; ++i) 
#define REPR(i,k,n) for (i = k; i >= n; --i) 

using ll = long long;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector<ll> v(n);
    for(ll& x : v)
      cin >> x;
    sort(v.begin(), v.end());
    bool flag = true;
    rep(i, n - 1){
      if(v[i + 1] - v[i] > 1){
        flag = false;
        break;
      }
    }
    if(flag)
      cout << "YES\n";
    
    else
      cout << "NO\n";
    
  }
	return 0;
}