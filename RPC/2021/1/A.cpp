#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, k, n) for (int i = k; i < n; ++i)
#define loop(h) for (int hi = 0; hi < h; hi++)
#define ii pair<int, int>
using ll = long long;
double sv = 0, sa = 0;

void sacar_nota(double x) {
  double cont = 0;
  rep(i, 0, 21) {
    if (abs((cont * sv) - x) <= 2.5 * sv) {
      if (cont * sv > x) {
        cout << cont << " UP\n";
      }
      if (cont * sv < x) {
        cout << cont << " DOWN\n";
      }
      if (cont * sv == x) {
        cout << cont << " SAME\n";
      }
      break;
    }
    cont += 5;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(0);
  int t, a, s;
  cin >> t;
  do {
    cin >> a >> s;
    double v[a], aux;
    sv = 0;
    sa = 0;
    loop(a) {
      cin >> v[hi];
      sv += v[hi];
    }
    rep(i, 0, s) {
      loop(a) {
        cin >> aux;
        sa += v[hi] * aux / 100;
      }
      sacar_nota(sa * 100);
      sa = 0;
    }
  } while (--t && cout << '\n');
  return 0;
}
