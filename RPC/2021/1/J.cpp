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
  int t;
  unsigned long long n;
  cin >> t;
  loop(t) {
    cin >> n;
    cout << (n * (n + 1) * (2 * n + 1) / 6 + n * (n + 1) / 2) / 2 << '\n';
  }
  return 0;
}
