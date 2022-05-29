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

  int t, n;
  cin >> t;
  while(t--) {
    cin >> n;
    vector<int> v(n);
    for (int& x : v)
      cin >> x;

    sort(v.begin(), v.end());
    int sol = 0, i = v.size();

    for (int x : v) {
      int sol1 = min(i, x);
      sol = max(sol, sol1);
      i--;
    }
    cout << sol << '\n';
  }

  return 0;
}
