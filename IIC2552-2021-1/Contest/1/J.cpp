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
  int n;
  string s;
  read(n, s);
  set<int> letras;
  rep(i, n) letras.insert(s[i]);

  map<char, vector<int>> a;
  int sol = 100000;

  rep(i, n) {
    if (!a.count(s[i])) {
      a[s[i]] = {i};
    } else {
      a[s[i]].push_back(i);
    }
  }
  rep(i, n) {
    int sol1 = 0;
    for (auto x : a) {
      auto up = lower_bound(x.second.begin(), x.second.end(), i);
      if ((up - x.second.begin()) == int(x.second.size())) {
        sol1 = -1;
        break;
      }
      sol1 = max(sol1, x.second[(up - x.second.begin())] + 1 - i);
    }
    a[s[i]].erase(a[s[i]].begin());
    if (sol1 != -1) {
      // print(sol1);
      sol = min(sol1, sol);
    }
  }
  print(sol);
  return 0;
}
