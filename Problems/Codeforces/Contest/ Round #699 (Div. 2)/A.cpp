#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, k, n) for (int i = k; i < n; ++i)
#define loop(h) for (int hi = 0; hi < h; hi++)
#define ii pair<int, int>
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  int t, a, b;
  string s;
  cin >> t;
  loop(t) {
    bool si = true;
    int u = 0, d = 0, r = 0, l = 0;
    cin >> a >> b >> s;
    for (int i = 0; i < s.length(); i++) {
      switch (s[i]) {
        case 'U':
          u++;
          break;

        case 'D':
          d++;
          break;

        case 'R':
          r++;
          break;

        case 'L':
          l++;
          break;

        default:
          break;
      }
    }
    int x = r - l, y = u - d;
    
    if ((a - x) < 0) {
      si = (si and r >= abs(a - x));
    }
    if ((a - x) > 0) {
      si = (si and l >= abs(a - x));
    }
    if ((b - y) < 0) {
      si = (si and u >= abs(b - y));
    }
    if ((b - y) > 0) {
      si = (si and d >= abs(b - y));
    }
    if (si)
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}
