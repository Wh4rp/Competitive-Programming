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

  int n, k1, sol = 0;
  string aux, aux1;
  read(n, k1);
  vector<string> v(n);
  set<string> s;
  for (string& x : v) {
    read(x);
    s.insert(x);
  }

  map<char, int> ci;
  map<int, char> ic;

  ci['S'] = 1;
  ci['E'] = 2;
  ci['T'] = 3;

  ic[3] = 'T';
  ic[4] = 'E';
  ic[5] = 'S';

  rep(i, n - 1) {
    rep_(j, i + 1, n) {
      aux = "";
      rep(k, k1) {
        if (v[i][k] == v[j][k])
          aux1 = v[i][k];
        else {
          aux1 = ic[ci[v[i][k]] + ci[v[j][k]]];
        }
        aux += aux1;
      }
      if (s.count(aux))
        sol++;
    }
  }
  print(sol / 3);
  return 0;
}
