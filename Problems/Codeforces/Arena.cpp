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

  int t;
  cin >> t;
  while(t--) {
    int n, ans = 0;
    cin >> n;
    int v[n];
    rep(i, n) cin >> v[i];
    int mini = *min_element(v, v+n);
    rep(i, n) if (v[i] > mini) ans++;
    cout << ans << '\n';
  }
  return 0;
}
