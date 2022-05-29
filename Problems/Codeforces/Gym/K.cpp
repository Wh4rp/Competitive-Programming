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
  
  string a, b;
  set<char> s;
  multiset<char> A, B;
  getline(cin, a);
  getline(cin, b);
  for(int i = 0; i < a.size(); i++){
  	A.insert(a[i]);
  }
  for(int i = 0; i < b.size(); i++){
  	B.insert(b[i]);
  }
  for(auto x : A){
  	if(B.count(x) == 2 * A.count(x)){
  		s.insert(x);
  	}
  }
  for(auto x : s){
  	cout << x;
  }
  cout << '\n';
  
  return 0;
}