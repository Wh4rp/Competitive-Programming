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
  set<pair<int, int>> vertices;
  set<int> axisx, axisy;
  int a, b, c, d;
  loop(4) {
    read(a, b, c, d);
    if ((a != c && b != d) || (a == c && b == d)) {
      print("NO");
      return 0;
    }
    vertices.insert({a, b});
    vertices.insert({c, d});
    if (a == c)
      axisx.insert(a);
    if (b == d)
      axisy.insert(b);
  }
  if (int(vertices.size()) == 4 && int(axisx.size()) == 2 &&
      int(axisy.size()) == 2) {
    print("YES");
  } else
    print("NO");
  return 0;
}
