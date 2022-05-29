#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
#define loop(h) for (int hi = 0; hi < h; hi++)
#define ii pair<int, int>
using ll = long long;

template <typename First>
bool read(First& t) {
  if (cin >> t)
    return true;
  return false;
}
template <typename First, typename... Args>
bool read(First& f, Args&... args) {
  cin >> f;
  return read(forward<Args&>(args)...);
}

// VARIADIC OUTPUT
template <typename T>
void print(T&& t) {
  cout << t << "\n";
}
template <typename First, typename... Args>
void print(First&& f, Args&&... args) {
  cout << f << " ";
  print(forward<Args&&>(args)...);
}
template <typename T>
void printLn(T&& t) {
  cout << t << "\n";
}
template <typename First, typename... Args>
void printLn(First&& f, Args&&... args) {
  cout << f << "\n";
  printLn(forward<Args&&>(args)...);
}

ll n, m, a[100010], b[100010];

ll f(ll x) {
  ll moves = 0LL;
  rep(i, n) {
    if (a[i] < x)
      moves += x - a[i];
  }
  rep(i, m) {
    if (b[i] > x)
      moves += b[i] - x;
  }
  return moves;
}
ll ternary_search() {
  ll l = 0LL, r = 1000000000LL;
  while (l < r) {
    ll m = (l + r) >> 1;
    if (f(m + 1) >= f(m))
      r = m;
    else
      l = m + 1;
  }
  return f(l);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  read(n, m);
  rep(i, n) read(a[i]);
  rep(i, m) read(b[i]);
  print(ternary_search());
  return 0;
}