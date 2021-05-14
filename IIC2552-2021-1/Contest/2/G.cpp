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
  int aux;
  vector<pair<int, int>> xd;
  stack<int> xd2;
  string s;
  read(s);
  rep(i, int(s.length())) {
    if (s[i] == '(') {
      xd2.push(i);
    }
    if (s[i] == ')') {
      aux = xd2.top();
      xd2.pop();
      xd.push_back({aux, i});
    }
  }
  set<string> sol;
  for (int i = (1 << int(xd.size())) - 1; i > 0; i--) {
    set<int> no_tomar;
    for (int j = 0; j < int(xd.size()); j++) {
      if (i & (1 << j)) {
        // cout << j << " ";
        int x = xd[j].first, y = xd[j].second;
        no_tomar.insert(x);
        no_tomar.insert(y);
      }
    }
    // cout << '\n';
    string sol_S = "";
    rep(i, int(s.length())) {
      if (no_tomar.count(i) == 0) {
        sol_S += s[i];
      }
    }
    sol.insert(sol_S);
  }
  for (string x : sol) {
    print(x);
  }
  return 0;
}
