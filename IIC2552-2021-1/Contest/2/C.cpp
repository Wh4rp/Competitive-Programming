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

  ll t, n, m;
  read(t);
  loop(t) {
    read(n);
    ll v[n + 1];
    rep(i, n + 1) read(v[i]);

    read(m);
    ll w[m + 1], z[n + m + 1];
    rep(i, m + 1) read(w[i]);
    rep(k, n + m + 1) z[k] = 0;

    rep(i, n + 1) {
      rep(j, m + 1) { z[i + j] += v[i] * w[j]; }
    }

    print(n + m);
    rep(k, n + m + 1) cout << z[k] << " \n"[k == (n + m)];
  }
  return 0;
}
