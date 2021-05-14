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

  int n1, mas = 0, a = 0, b = 1;
  string s;
  vector<string> v;
  while (getline(cin, s)) {
    v.push_back(s);
    mas = max(mas, int(s.size()));
  }
  rep(i, mas + 2) cout << "*";
  cout << "\n";

  for (string x : v) {
    n1 = mas - int(x.size());
    cout << "*";
    if ((n1 % 2) == 1) {
      rep(i, (n1 / 2) + a) cout << " ";
      cout << x;
      rep(i, (n1 / 2) + b) cout << " ";
      swap(a, b);
    } else {
      rep(i, n1 / 2) cout << " ";
      cout << x;
      rep(i, n1 / 2) cout << " ";
    }
    cout << "*\n";
  }

  rep(i, mas + 2) cout << "*";
  cout << '\n';
  return 0;
}
