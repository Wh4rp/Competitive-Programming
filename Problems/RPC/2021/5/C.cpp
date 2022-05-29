#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
#define loop(h) for (int hi = 0; hi < h; hi++)
#define ii pair<int, int>
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);

  int n;
  cin >> n;
  vector<int> v(n);
  for (int& x : v) {
    cin >> x;
  }
  sort(v.begin(), v.end());

  int sol = 100000000;
  rep(i, n) {
    rep(j, n) {
      if (i == j)
        continue;
      int aux = 0;
      rep(k, n) {
        int x = (v[i] - v[k]);
        int y = (v[j] - v[k]);
        aux += min(x * x, y * y);
      }
      sol = min(sol, aux);
    }
    }
  cout << sol << '\n';
  return 0;
}