#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

bool in_interval(int x, int a, int b) {
  return a <= x && x <= b;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  int t, x, y;
  string s;
  cin >> t;
  while(t--) {
    map<char, int> m = {{'L', 0}, {'R', 0}, {'D', 0}, {'U', 0}};
    cin >> x >> y >> s;
    rep(i, s.size())
      m[s[i]]++;

    if (in_interval(x, -m['L'], m['R']) && in_interval(y, -m['D'], m['U']))
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}
