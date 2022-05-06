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
ll n;
double a[200010], s[200010];

double f(double x) {
  double weakness = 0.0, minsum = 0, maxsum = 0, sumnow;
  rep(i, n) {
    sumnow = (s[i] - x * (i + 1));
    weakness = max(weakness, max(abs(sumnow - minsum), abs(sumnow - maxsum)));

    // print(weakness, minsum, maxsum);
    minsum = min(minsum, sumnow);
    maxsum = max(maxsum, sumnow);
  }
  return weakness;
}

double ternary_search() {
  int times = 100;
  double l = -20000, r = 20000;
  while (times--) {
    double d = (r - l) / 3.0;
    double m1 = l + d, m2 = r - d;
    double f1 = f(m1), f2 = f(m2);
    if (f1 <= f2)
      r = m2;
    if (f1 >= f2)
      l = m1;
    // print("l:", l, "r:", r, f((l + r) * .5));
  }
  return f(l);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  read(n);
  rep(i, n) read(a[i]);
  s[0] = a[0];
  rep_(i, 1, n) s[i] = a[i] + s[i - 1];

  double sol = ternary_search();
  print(sol);
  /*
  rep(i, n) { cout << a[i] - 4.5 << " \n"[i == n - 1]; }
  rep(i, n) { cout << s[i] - 4.5 * (i + 1) << " \n"[i == n - 1]; }
  print("");
  print(f(4.5));
  */

  return 0;
}