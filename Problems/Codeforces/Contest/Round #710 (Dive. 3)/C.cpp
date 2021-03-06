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
  string s1, s2;
  loop(t) {
    read(s1, s2);
    int sol = 0;
    if (s1.length() < s2.length())
      swap(s1, s2);
    int n = s1.length(), m = s2.length();
    rep(i, n) {
      rep(j, m) {
        int sol_aux = 0, I = i, J = j;
        while (s1[I] == s2[J]) {
          sol_aux++;
          I++;
          J++;
          if (I == n || J == m)
            break;
        }
        sol = max(sol, sol_aux);
      }
    }
  }
  return 0;
}
