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
  
  int t;
  string s;
  cin >> t;
  while (t --){
  	cin >> s;
  	int i = 0, a = -1, b = -1, c = -1, sol = 200001;
  	  	for (auto x: s){
  		if (x == '1'){
  			a = i;
  		}
  		if (x == '2'){
  			b = i;
  		}
  		if (x == '3'){
  			c = i;
  		}
  		if (a != -1 && b != -1 && c != -1) 
  			sol = min(sol, i - min(a, min(b, c)) + 1);
  		i++;
  	}
  	if (a != -1 && b != -1 && c != -1) 
  		cout << sol << '\n';
  	else 
  		cout << "0\n";
  }
  
  return 0;
}