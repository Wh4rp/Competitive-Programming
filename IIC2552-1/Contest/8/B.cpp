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

  vector<int> v;
  int n, i = 1;

  cin >> n;

  while(i != n && n - i > i){
  	v.push_back(i);
  	n -= i;
  	i++;
  }
  v.push_back(n);

  cout << v.size() << '\n';
  for(auto it = v.begin(); it != v.end(); it++){
  	cout << *it << " \n"[it == v.end() - 1];
  }
  return 0;
}