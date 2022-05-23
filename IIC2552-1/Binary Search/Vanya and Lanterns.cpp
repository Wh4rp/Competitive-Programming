#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
#define loop(h) for (int hi = 0; hi < h; hi++)
#define ii pair<int, int>
using ll = long long;

template <typename First>
void read(First& t) {
  cin >> t;
}
template <typename First, typename... Args>
void read(First& f, Args&... args) {
  cin >> f;
  read(forward<Args&>(args)...);
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);

  int n, l;
  read(n, l);
  vector<ll> lanters(n);
  for (ll& x : lanters)
    read(x);
  sort(lanters.begin(), lanters.end());

  double left = 0, right = l, d;
  loop(100) {
    bool L = true;
    d = (left + right) * 0.5;

    rep(i, n - 1) {
      if (lanters[i] != lanters[i + 1] && lanters[i] + d < lanters[i + 1] - d) {
        L = false;
        break;
      }
    }
    if (lanters[0] - d > 0 || lanters[n - 1] + d < l)
      L = false;
    if (L)
      right = d;
    else
      left = d;
  }
  print(d);

  return 0;
}
