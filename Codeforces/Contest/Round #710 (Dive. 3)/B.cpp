#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, n) for (int i = n - 1; i >= 0; --i)
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
  string s;
  int n, k;
  loop(t) {
    read(n, k, s);
    int primero, ultimo, aux;
    vector<int> pos1, pos2;
    rep(i, n) {
      if (s[i] == '*') {
        pos1.push_back(i);
      }
    }

    rep_(i, n) {
      if (s[i] == '*') {
        pos2.push_back(i);
      }
    }

    primero = pos1[0];
    ultimo = pos2[0];
    int sol1, sol2;
    if (primero != ultimo) {
      sol1 = 2;
      sol2 = 2;
    }

    else {
      print(1);
      continue;
    }

    aux = primero;
    int i = 0;
    for (auto x : pos1) {
      // cout << (x - aux) << " ";
      if ((x - aux) > k) {
        aux = pos1[i - 1];
        sol1++;
      }
      i++;
    }
    // cout << '\n';
    aux = ultimo;
    i = 0;
    for (auto x : pos2) {
      // cout << (aux - x) << " ";
      if ((aux - x) > k) {
        aux = pos2[i - 1];
        sol2++;
      }
      i++;
    }
    // cout << '\n';
    print(min(sol1, sol2));
  }
  return 0;
}
