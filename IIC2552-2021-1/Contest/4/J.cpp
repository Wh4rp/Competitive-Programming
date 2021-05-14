#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;

ll N;
ll D[100010], v[100010], L = 0;

double f(double x) {
  double mini = DBL_MAX, maxi = -1.0;
  rep(i, N) {
    mini = min(mini, v[i] * x - D[i]);
    maxi = max(maxi, v[i] * x - D[i]);
  }
  return (maxi - mini);
}

void ternary_search() {
  int times = 60;
  double l = L, r = 1e9;
  while (times--) {
    double d = (r - l) / 3.0;
    double m1 = l + d, m2 = r - d;
    double f1 = f(m1), f2 = f(m2);
    if (f1 <= f2)
      r = m2;
    if (f1 >= f2)
      l = m1;
  }
  cout << f((l + r) * .5) << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);

  while (cin >> (N) && N != 0) {
    rep(i, N) {
      cin >> D[i] >> v[i];
      L = max(L, D[i]);
      D[i] *= v[i];
    }
    ternary_search();
    L = 0.0;
  }

  return 0;
}