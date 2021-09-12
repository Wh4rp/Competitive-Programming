#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep_(i, k, n) for (ll i = k; i < n; ++i)
#define loop(h) for (ll hi = 0; hi < h; hi++)
#define ii pair<int, int>
using ll = long long;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  set<pair<int, int>> vertices;
  set<int> axisx, axisy;
  int a, b, c, d;
  loop(4) {
    cin >> a >> b >> c >> d;
    if ((a != c && b != d) || (a == c && b == d)) {
      cout << "NO\n";
      return 0;
    }
    vertices.insert({a, b});
    vertices.insert({c, d});
    if (a == c)
      axisx.insert(a);
    if (b == d)
      axisy.insert(b);
  }
  if (int(vertices.size()) == 4 && int(axisx.size()) == 2 &&
      int(axisy.size()) == 2) {
    cout << "YES\n";
  } else
    cout << "NO\n";
  return 0;
}