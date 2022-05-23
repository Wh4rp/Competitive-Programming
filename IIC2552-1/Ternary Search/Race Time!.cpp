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
ll N;
double K;
double S[100010], D[100010];
double f(double x) {
  double mini = DBL_MAX, maxi = -1.0;
  rep(i, N) {
    mini = min(mini, S[i] * x + D[i]);
    maxi = max(maxi, S[i] * x + D[i]);
  }
  return (maxi - mini);
}

double ternary_search() {
  int times = 1000;
  double l = 0, r = K;
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
  cout.precision(6);

  read(N, K);
  rep(i, N) read(S[i], D[i]);
  print(ternary_search());

  return 0;
}