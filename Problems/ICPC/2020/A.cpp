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
  
  int n, aux1 = 0;
  cin >> n;
  vector<int> v(n);
  for(int& x : v){
  	cin >> x;
  	x += aux;
  	aux = x;
  }
  for(int& x : v){
  	cout << x << ' ';
  }
  
  return 0;
}