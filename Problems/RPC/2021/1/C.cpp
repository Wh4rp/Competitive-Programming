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

  ll a, b, aux;
  while (cin >> a >> b && (a != 0 && b != 0)) {
    unordered_set<ll> A;
    ll aib = 0;
    loop(a) {
      cin >> aux;
      A.insert(aux);
    }
    loop(b) {
      cin >> aux;
      if (A.count(aux))
        aib++;
    }
    cout << a - aib << " " << aib << " " << b - aib << " " << a + b - aib
         << '\n';
  }

  return 0;
}
