// source :
// https://github.com/BenjaminRubio/CompetitiveProgramming/blob/master/Material/Geometry/2D.cpp

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
#define loop(h) for (int hi = 0; hi < h; hi++)
#define ii pair<int, int>
#define pdd pair<double, double>
using ll = long long;

const double PI = acos(-1.0L);
const double EPS = 1e-6;

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

void lineFromPoints(pdd P, pdd Q, double& a, double& b, double& c) {
  a = Q.second - P.second;
  b = P.first - Q.first;
  c = a * (P.first) + b * (P.second);
}

typedef double T;
struct P {
  T x, y;
  P() {}
  P(T x, T y) : x(x), y(y) {}

  P operator+(const P& p) const { return P(x + p.x, y + p.y); }
  P operator-(const P& p) const { return P(x - p.x, y - p.y); }
  P operator*(const double& c) const { return P(x * c, y * c); }
  P operator/(const double& c) const { return P(x / c, y / c); }
  T operator^(const P& p) const { return x * p.y - y * p.x; }
  T operator*(const P& p) const { return x * p.x + y * p.y; }
  bool operator==(const P& p) const {
    return abs(x - p.x) + abs(y - p.y) < EPS;
  }
  bool operator<(const P& p) const {
    return abs(x - p.x) > EPS ? p.x - x > EPS : p.y - y > EPS;
  }

  T norm2() const { return x * x + y * y; }
  double norm() const { return sqrt(norm2()); }
  double ang() {
    double a = atan2(y, x);
    if (a < 0)
      a += 2. * PI;
    return a;
  }
  P unit() { return (*this) / norm(); }
  P perp() { return P(-y, x); }
  P rot(P r) { return P((*this) ^ r, (*this) * r); }
  P rot(double a) { return rot(P(sin(a), cos(a))); }
};

P bary(P& A, P& B, P& C, double a, double b, double c) {
  return (A * a + B * b + C * c) / (a + b + c);
}

P circum(P& A, P& B, P& C) {
  double a = (B - C).norm2(), b = (C - A).norm2(), c = (A - B).norm2();
  return bary(A, B, C, a * (b + c - a), b * (c + a - b), c * (a + b - c));
}
T turn(P& a, P& b, P& c) {
  return (b - a) ^ (c - a);
}

bool inDisk(P& a, P& b, P& p) {
  return (a - p) * (b - p) <= 0;
}

bool onSegment(P& a, P& b, P& p) {
  return abs(turn(a, b, p)) < EPS && inDisk(a, b, p);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(12);

  double r, x, y;
  int n;
  read(r, n);
  vector<P> v;

  rep(i, n) {
    read(x, y);
    P xd = P(x, y);
    v.push_back(xd);
  }

  int sol = 1;
  rep(i, n - 2) {
    rep_(j, i + 1, n - 1) {
      rep_(k, j + 1, n) {
        int cont = 0;
        print(v[i].x, v[i].y, v[j].x, v[j].y, v[k].x, v[k].y);

        if (onSegment(v[i], v[j], v[k])) {
          // print("Colineales");
          int cont1 = 0, cont2 = 0, cont3 = 0;
          P probar1 = (v[i] + v[j]) / 2;

          P probar2 = (v[k] + v[j]) / 2;

          P probar3 = (v[i] + v[k]) / 2;

          for (auto x : v) {
            if ((x - probar1).norm() <= r - 1e-6)
              cont1++;
          }
          for (auto x : v) {
            if ((x - probar2).norm() <= r - 1e-6)
              cont2++;
          }

          for (auto x : v) {
            if ((x - probar3).norm() <= r - 1e-6)
              cont3++;
          }
          cont = max(cont1, max(cont2, cont3));
        } else {
          P probar = circum(v[i], v[j], v[k]);
          for (auto x : v) {
            if ((x - probar).norm() <= r - 1e-6)
              cont++;
          }
        }
        sol = max(sol, cont);
      }
    }
  }
  rep(i, n - 1) {
    rep_(j, i + 1, n) {
      int cont = 0;
      P probar = (v[i] + v[j]) / 2;
      for (auto x : v) {
        if ((x - probar).norm() <= r - 1e-6)
          cont++;
      }
      sol = max(sol, cont);
    }
  }

  print(sol);

  return 0;
}
