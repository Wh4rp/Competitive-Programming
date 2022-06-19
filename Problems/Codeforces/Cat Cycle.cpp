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

  ll t, n, k, sol;
  cin >> t;
  while(t--) {
    cin >> n >> k;
    cout << (k - 1 + (n % 2) * (k - 1) / (n / 2)) % n + 1 << '\n';
  }
  return 0;
}
