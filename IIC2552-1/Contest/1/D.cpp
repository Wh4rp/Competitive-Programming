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

  int t, a, b, c, r, x, y;
  read(t);
  loop(t) {
    read(a, b, c, r);
    if (a > b)
      swap(a, b);
    x = c - r;
    y = c + r;
    if (c < a) {
      if (y < a) {
        print(b - a);
      }
      if (a <= y && y <= b) {
        print(b - y);
      }
      if (b < y) {
        print(0);
      }
    }
    if (b < c) {
      if (b < x) {
        print(b - a);
      }
      if (a <= x && x <= b) {
        print(x - a);
      }
      if (x < a) {
        print(0);
      }
    }
    if (a <= c && c <= b) {
      print(b - min(b, y) + max(a, x) - a);
    }
  }

  return 0;
}
