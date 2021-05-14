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

  int t, n, aux;
  string s, auxs;
  read(t);
  loop(t) {
    read(n);
    map<string, unordered_set<string>> ingre_native;
    map<string, unordered_set<string>> ingre_foreign;
    rep(i, n) {
      read(s);
      read(aux);
      rep(k, aux) {
        read(auxs);
        if (ingre_native.count(auxs) == 0) {
          ingre_native[auxs] = {s};
        } else {
          ingre_native[auxs].insert(s);
        }
      }

      read(aux);
      rep(k, aux) {
        read(auxs);
        if (ingre_foreign.count(auxs) == 0) {
          ingre_foreign[auxs] = {s};
        } else {
          ingre_foreign[auxs].insert(s);
        }
      }
    }
    for (auto x : ingre_native) {
      set<string> ingre;
      for (auto y : ingre_foreign) {
        if (x.second == y.second) {
          ingre.insert(y.first);
        }
      }
      if (!ingre.empty()) {
        for (auto y : ingre) {
          cout << "(" << x.first << ", " << y << ")\n";
        }
      }
    }
    print("");
  }

  return 0;
}
