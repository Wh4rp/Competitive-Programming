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
  	int a[n];
  	rep(i, n) cin >> a[i];
  	rep(i, n - 1)
  		rep_(j, i + 1, n){
  			if((a[i] * a[j]) % 2){
  			  cout << __gcd(a[i], a[j]) << '\n';
  				if(__gcd(a[i], a[j]) != 1) sol++;
  			}
  			else sol++;
  		}
  			
  		
  	cout << sol << '\n';
  }
  
  
  return 0;
}