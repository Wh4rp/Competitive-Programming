#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
#define loop(h) for (int hi = 0; hi < h; hi++)
#define ii pair<int, int>
using ll = long long;
using db = double;
const db PI = acos(-1.0L);
const db EPS = 1e-12;
typedef db T;
struct P {
  T x, y;
  P() {}
  P(T x, T y) : x(x), y(y) {}

  P operator+(const P& p) const { return P(x + p.x, y + p.y); }
  P operator-(const P& p) const { return P(x - p.x, y - p.y); }
  P operator*(const db& c) const { return P(x * c, y * c); }
  P operator/(const db& c) const { return P(x / c, y / c); }
  T operator^(const P& p) const { return x * p.y - y * p.x; }
  T operator*(const P& p) const { return x * p.x + y * p.y; }
  bool operator==(const P& p) const {
    return abs(x - p.x) + abs(y - p.y) < EPS;
  }
  bool operator<(const P& p) const {
    return abs(x - p.x) > EPS ? p.x - x > EPS : p.y - y > EPS;
  }

  T norm2() const { return x * x + y * y; }
  db norm() const { return sqrt(norm2()); }
  db ang() {
    db a = atan2(y, x);
    if (a < 0)
      a += 2. * PI;
    return a;
  }
  P unit() { return (*this) / norm(); }
  P perp() { return P(-y, x); }
  P rot(P r) { return P((*this) ^ r, (*this) * r); }
  P rot(db a) { return rot(P(sin(a), cos(a))); }
};

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
P A, B, C, D;

double f(double t) {
  P E = A + (B - A) * t - C - (D - C) * t;
  return E.norm2();
}

double ternary_search() {
  int times = 100;
  double l = 0, r = 1;
  while (times--) {
    double d = (r - l) / 3.0;
    double m1 = l + d, m2 = r - d;
    double f1 = f(m1), f2 = f(m2);
    if (f1 <= f2)
      r = m2;
    if (f1 >= f2)
      l = m1;
  }
  return sqrt(f((l + r) * .5));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  ll n, m;
  read(n);
  deque<P> Shadow, Lydia;
  rep(i, n) {
    read(A.x, A.y);
    Shadow.push_back(A);
  }
  read(m);
  rep(i, m) {
    read(A.x, A.y);
    Lydia.push_back(A);
  }
  double sol = DBL_MAX;
  while (n >= 2 && m >= 2) {
    A = Shadow.front();
    Shadow.pop_front();
    B = Shadow.front();

    C = Lydia.front();
    Lydia.pop_front();
    D = Lydia.front();

    n--, m--;

    P S = B - A, L = D - C;

    if (S.norm2() > L.norm2()) {
      B = A + S * (L.norm()) / S.norm();
      Shadow.push_front(B);
      n++;
    }

    if (S.norm2() < L.norm2()) {
      D = C + L * (S.norm()) / L.norm();
      Lydia.push_front(D);
      m++;
    }

    sol = min(sol, ternary_search());
  }
  print(sol);
  return 0;
}