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

  int n;
  read(n);
  double bl, br;
  vector<pair<ll, ll>> p(n);
  rep(i, n) read(p[i].first);
  rep(i, n) read(p[i].second);
  sort(p.begin(), p.end());
  double l = 0, r = 1e9, t;
  loop(100) {
    t = (l + r) * 0.5;
    bl = p[0].first * 1.0 - p[0].second * 1.0 * t;
    br = p[0].first * 1.0 + p[0].second * 1.0 * t;
    bool junta = true;
    rep(i, n) {
      bl = max(bl, p[i].first - p[i].second * t);
      br = min(br, p[i].first + p[i].second * t);
      if (bl > br) {
        junta = false;
        break;
      }
    }
    if (junta)
      r = t;
    else
      l = t;
  }
  print(t);

  return 0;
}
