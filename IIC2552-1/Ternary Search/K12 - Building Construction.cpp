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
ll N, C[10010], H[10010];

ll f(ll x) {
  ll cost = 0;
  rep(j, N) { cost += abs(x - H[j]) * C[j]; }
  return cost;
}
ll ternary_search() {
  ll l = 0, r = 10000;
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
  ll T;
  read(T);
  loop(T) {
    read(N);
    rep(i, N) { read(H[i]); }
    rep(i, N) { read(C[i]); }
    print(ternary_search());
  }

  return 0;
}