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

  int t, a, b, c, r, x, y;
  cin >> t;
  while(t--) {
    cin >> a >> b >> c >> r;
    if (a > b)
      swap(a, b);
    x = c - r;
    y = c + r;
    if (c < a) {
      if (y < a) {
        cout << b - a << '\n';
      }
      if (a <= y && y <= b) {
        cout << b - y << '\n';
      }
      if (b < y) {
        cout << 0 << '\n';
      }
    }
    if (b < c) {
      if (b < x) {
        cout << b - a << '\n';
      }
      if (a <= x && x <= b) {
        cout << x - a << '\n';
      }
      if (x < a) {
        cout << 0 << '\n';
      }
    }
    if (a <= c && c <= b) {
      cout << b - min(b, y) + max(a, x) - a << '\n';
    }
  }

  return 0;
}
