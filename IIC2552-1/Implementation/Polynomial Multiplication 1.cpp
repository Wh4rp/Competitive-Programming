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
    int n, m;
    cin >> n;
    vector<ll> v(n + 1);
    for(ll& x : v){
      cin >> x;
    }
    cin >> m;
    vector<ll> w(m + 1);
    for(ll& x : w){
      cin >> x;
    }
    vector<ll> s(n + m + 1, 0);
    for(int i = 0; i < n + m + 1; i ++){
      for(int j = 0; j < i + 1; j++){
        if(j < n + 1 && i - j < m + 1){          
          s[i] += v[j] * w[i - j];
        }
      }
    }
    cout << n + m << '\n';
    for(ll x : s){
      cout << x << ' ';
    }
    cout << '\n';
  }
	return 0;
}
