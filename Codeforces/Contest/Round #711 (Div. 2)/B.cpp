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

  int t;
  read(t);
  loop(t) {
    map<int, int> mapa;
    int n, w, aux, maxi = 0;
    read(n, w);
    rep(i, n) {
      read(aux);
      if (mapa.count(-1 * aux)) {
        mapa[-1 * aux]++;
      } else
        mapa[-1 * aux] = 1;
      maxi = max(maxi, aux);
    }
    int nivel = 0, w1 = w, nivel_max = 0;
    for (auto& x : mapa) {
      aux = -1 * x.first;
    }
  }

  return 0;
}
