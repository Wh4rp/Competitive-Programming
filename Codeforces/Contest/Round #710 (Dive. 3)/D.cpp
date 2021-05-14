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
  read(t);
  loop(t) {
    read(n);
    unordered_map<int, int> xd;
    rep(i, n) {
      read(aux);
      if (!xd.count(aux))
        xd[aux] = 1;
      else
        xd[aux]++;
    }
    priority_queue<int> xdd;
    for (auto x : xd) {
      xdd.push(x.second);
    }
    while (int(xdd.size()) > 1) {
      int a = xdd.top();
      xdd.pop();
      int b = xdd.top();
      xdd.pop();
      a--;
      b--;
      if (a != 0)
        xdd.push(a);
      if (b != 0)
        xdd.push(b);
    }
    if (int(xdd.size()) == 1) {
      print(xdd.top());
    } else {
      print(0);
    }
  }
  return 0;
}
