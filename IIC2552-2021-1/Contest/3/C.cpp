#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
#define loop(h) for (int hi = 0; hi < h; hi++)  // aa
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
  int t;
  ll v[500010], w[500010];
  double ans = -1;
  read(t);

  rep(i, t) { read(v[i], w[i]); }

  double l = 0, r = 2e9, m;
  loop(61) {
    m = (l + r) * 0.5;
    bool colision = false;
    double mas_d = -1e20, pos;
    rep(i, t) {
      pos = v[i] * 0.1 + w[i] * 0.1 * m;
      if (w[i] < 0) {
        if (pos < mas_d)
          colision = true;
      } else {
        mas_d = max(mas_d, pos);
      }
    }
    if (colision) {
      ans = r = m;
    } else
      l = m;
  }
  print(ans);

  return 0;
}