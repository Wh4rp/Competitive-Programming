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

  int t, n;
  read(t);
  loop(t) {
    read(n);
    int c[3] = {0, 0, 0}, aux, sol = -1, mayores = 0;
    rep(i, n) {
      read(aux);
      c[aux % 3]++;
    }
    if (c[0] == c[1] && c[1] == c[2]) {
      print(0);
      continue;
    }
    rep(i, 3) {
      if (c[i] > (n / 3))
        mayores++;
    }
    if (mayores == 2) {
      if (c[0] < n / 3) {
        sol = 2 * (c[1] - (n / 3)) + (c[2] - (n / 3));
      }
      if (c[1] < n / 3) {
        sol = 2 * (c[2] - (n / 3)) + (c[0] - (n / 3));
      }
      if (c[2] < n / 3) {
        sol = 2 * (c[0] - (n / 3)) + (c[1] - (n / 3));
      }
    }
    if (mayores == 1) {
      if (c[0] > n / 3) {
        sol = 2 * ((n / 3) - c[2]) + ((n / 3) - c[1]);
      }
      if (c[1] > n / 3) {
        sol = 2 * ((n / 3) - c[0]) + ((n / 3) - c[2]);
      }
      if (c[2] > n / 3) {
        sol = 2 * ((n / 3) - c[1]) + ((n / 3) - c[0]);
      }
    }

    print(sol);
  }

  return 0;
}
