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
  
  set<char> s;
  string a;
  cin >> a;
  rep(i, a.length()){
    s.insert(a[i]);
  }
  cout << (s.size()%2 == 0? "CHAT WITH HER!\n" : "IGNORE HIM!\n");
  
  return 0;
}