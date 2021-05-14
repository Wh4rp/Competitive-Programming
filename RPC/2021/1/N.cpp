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
  cout.precision(0);
  unordered_map<ll, pair<ll, ll>> hola;
  hola.insert({1, {0, 0}});
  hola.insert({2, {1, 0}});
  hola.insert({4, {2, 0}});
  hola.insert({8, {3, 0}});
  hola.insert({16, {4, 0}});
  hola.insert({32, {5, 0}});
  hola.insert({64, {6, 0}});
  hola.insert({5, {0, 1}});
  hola.insert({25, {0, 2}});
  hola.insert({10, {1, 1}});
  hola.insert({50, {1, 2}});
  hola.insert({100, {2, 2}});
  hola.insert({40, {3, 2}});
  ll a, n;
  while (cin >> a >> n) {
  }
  return 0;
}
