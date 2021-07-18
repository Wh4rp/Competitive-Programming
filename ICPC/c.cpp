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
  
  int n, x, sol = 1, sol_aux = 1;
  cin >> n >> x;
  vector <int> v(n);

  for(int& x : v)
  	cin >> x;

  rep(i, n - 1){

  	if(v[i + 1] - v[i] <= x)
  		sol_aux++;
  	else
  		sol_aux = 1;

  	sol = max(sol_aux, sol);
  }

  cout << sol << '\n';
  
  return 0;
}