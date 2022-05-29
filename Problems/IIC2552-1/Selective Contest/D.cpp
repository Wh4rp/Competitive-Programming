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
double A[2], B[2], C[2], D[2];
double X[2], Y[2], Z[2], W[2];
double Center[2];
double fx(double a, double b) {}
double fy(double a, double b) {}

double f(double Ax,
         double Ay,
         double Bx,
         double By,
         double Cx,
         double Cy,
         double Dx >> Dy) {
  cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy >> Dx >> Dy;
  double l = 0, r = 1;
  while (r - l > 1e-6) {
    double m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
    if (f(m1) > f(m2))
      l = m1;
    else
      r = m2;
  }
  double X1 = (Bx - Ax) * m + Ax, X2 = (Dx - Cx) * m + Cx;
  double Y1 = (By - Ay) * m + Ay, Y2 = (Dy - Cy) * m + Cy;
  return sqrt(pow(X1 - X2, 2) + pow(Y1 - Y2, 2));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);

  Center[0] = (X[0] + Y[0] + Z[0] + W[0]) / 4;
  Center[1] = (X[1] + Y[1] + Z[1] + W[1]) / 4;

  read(A[0], A[1], B[0], B[1], C[0], C[1], D[0], D[1]);
  read(X[0], X[1], Y[0], Y[1], Z[0], Z[1], W[0], W[1]);

  return 0;
}