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
  int t, n, m;
  cin >> t;
  loop(t) {
    cin >> n >> m;
    int a[n + 1], b[n + 1];
    vector<int> cm[n + 1];
    vector<ii> cc[n + 1];  // [color_a_cambiar], <posicion, color_antes

    rep(i, 0, n) {
      cin >> a[i + 1];
      cm[a[i + 1]] = i + 1;
    }
    rep(i, 0, n) {
      cin >> b[i + 1];
      if (b[i + 1] != a[i + 1]) {
        cc[b[i + 1]].push_back({i + 1, a[i + 1]});
      }
    }
  }

  return 0;
}
