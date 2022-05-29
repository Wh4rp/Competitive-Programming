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
    queue<pair<vector<int>, int>> fila;
    read(n);
    int sol[n + 1];
    vector<int> v(n);
    int ia = 0;
    map<int, int> indice;
    for (auto& x : v) {
      read(x);
      indice.insert({x, ia});
      ia++;
    }

    fila.push({v, 0});
    while (!fila.empty()) {
      pair<vector<int>, int> a_revisar;
      a_revisar = {fila.front().first, fila.front().second};
      fila.pop();
      int maxi = 0, idex_maxi = 0, i = 0;
      for (auto x : a_revisar.first) {
        if (maxi < x) {
          maxi = x;
          idex_maxi = i;
        }
        i++;
      }

      sol[indice[maxi]] = a_revisar.second;

      if (idex_maxi > 0) {
        vector<int> vl;
        for (int i = 0; i < idex_maxi; i++) {
          vl.push_back(a_revisar.first[i]);
        }
        fila.push({vl, a_revisar.second + 1});
      }
      if (idex_maxi < int(a_revisar.first.size()) - 1) {
        vector<int> vr;
        for (int i = idex_maxi + 1; i < int(a_revisar.first.size()); i++) {
          vr.push_back(a_revisar.first[i]);
        }
        fila.push({vr, a_revisar.second + 1});
      }
    }
    rep(i, n) cout << sol[i] << " \n"[i == (n - 1)];
  }

  return 0;
}
