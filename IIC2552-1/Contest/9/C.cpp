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
  	int n, sol = 0;
  	cin >> n;
  	vector<int> v(n);
  	for(int& x: v)
  		cin >> x;
  	sort(v.begin(), v.end());
  	while(n > 3){
  		int sol1 = 2 * v[0] + v[n - 2] + v[n - 1];
  		int sol2 = v[0] + 2 * v[1] + v[n - 1];
  		sol += min(sol1, sol2);
  		n -= 2;
  	}
  	if(n == 3){
  		sol += v[0] + v[1] + v[2];
  	}
  	if(n == 2){
  		sol += v[1];
  	}
  	if(n == 1){
  		sol += v[0];
  	}
  	cout << sol << '\n';
  }
  
  return 0;
}