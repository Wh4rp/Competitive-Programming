#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
const double pi = atan(1) * 4;
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
double b, c;
double f(double x) {
  return (x * x + b * x + c) / (sin(x));
}

double min_ternary_search() {
  int times = 1000;
  double l = 0, r = pi * 0.5;
  while (times--) {
    double d = (r - l) / 3.0;
    double m1 = l + d, m2 = r - d;
    double f1 = f(m1), f2 = f(m2);
    if (f1 <= f2)
      r = m2;
    if (f1 >= f2)
      l = m1;
  }
  return f((l + r) * .5);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  ll T;
  read(T);
  loop(T) {
    read(b, c);
    print(min_ternary_search());
  }
  return 0;
}