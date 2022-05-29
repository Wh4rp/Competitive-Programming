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
  ll n, a[3], b[3];
  cin >> n;
  rep(i, 3)
    cin >> a[i];
  rep(i, 3)
    cin >> b[i];
  ll sol = 
  cout << min(a[2], b[0]) + min(a[1], b[2]) + min(a[0], b[1]) << '\n';
  return 0;
}