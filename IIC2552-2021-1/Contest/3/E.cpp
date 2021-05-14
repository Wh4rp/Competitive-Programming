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

  int n, t;
  double l = -1000, r = 2000, c, time;
  read(n, t);
  vector<pair<ll, ll>> segmentos(n);

  for (auto& x : segmentos) {
    read(x.first, x.second);
    l = max(l, -x.second * 1.0);
  }
  loop(1000) {
    c = (l + r) * 0.5;
    time = 0;
    for (auto& x : segmentos) {
      time += x.first * 1.0 / (x.second * 1.0 + c);
    }
    if (time < t)
      r = c;
    else
      l = c;
  }

  print(c);

  return 0;
}
