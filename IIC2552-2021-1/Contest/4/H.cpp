#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  ll n, m, aux, cover = 0;
  ll cricriminal[1000010];
  cin >> n >> m;
  rep(i, n) cin >> (cricriminal[i]);
  for (int i = 0; i < n / 2; i += m) {
    cover += (cricriminal[n / 2] - cricriminal[i]) * 2;
  }
  for (int i = n - 1; i > n / 2; i -= m) {
    cover += (cricriminal[i] - cricriminal[n / 2]) * 2;
  }
  cout << cover << '\n';
  return 0;
}