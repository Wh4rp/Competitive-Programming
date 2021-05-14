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

  int a, b, base = 0, aux, aux1, sum = 0, sol = 0;
  read(a, b);
  aux = a;
  while (aux) {
    base = max(base, aux % 10);
    aux /= 10;
  }
  aux = b;
  while (aux) {
    base = max(base, aux % 10);
    aux /= 10;
  }

  base++;
  aux = a;
  aux1 = 1;
  while (aux) {
    sum += (aux % 10) * aux1;
    aux1 *= base;
    aux /= 10;
  }
  aux = b;
  aux1 = 1;
  while (aux) {
    sum += (aux % 10) * aux1;
    aux1 *= base;
    aux /= 10;
  }
  aux = sum;
  while (aux) {
    aux /= base;
    sol++;
  }
  print(sol);
  return 0;
}
