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
  
  string a, sol = "";

  cin >> a;
  int i = 0, n = a.length();
  bool noAs = false;
  rep(i, a.length()){
  	if(a[i] != 'a')
  		noAs = true;
  }
  if(noAs){
	while(a[i] == 'a' && i < n){
	  	sol += a[i];
		i++;
	}
	while(a[i] != 'a' && i < n){
	  	sol += char(a[i] - 1);
	  	i++;
	}
	while(i < n){
	  	sol += a[i];
	 	i++;
	}
	cout << sol << '\n';
  }
  else{
  	a[a.length() - 1] = 'z';
  	cout << a << '\n';
  }
  
  return 0;
}