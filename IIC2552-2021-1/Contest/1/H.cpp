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

  map<char, pair<int, int>> keyboard;
  keyboard['q'] = {0, 0};
  keyboard['w'] = {0, 1};
  keyboard['e'] = {0, 2};
  keyboard['r'] = {0, 3};
  keyboard['t'] = {0, 4};
  keyboard['y'] = {0, 5};
  keyboard['u'] = {0, 6};
  keyboard['i'] = {0, 7};
  keyboard['o'] = {0, 8};
  keyboard['p'] = {0, 9};
  keyboard['a'] = {1, 0};
  keyboard['s'] = {1, 1};
  keyboard['d'] = {1, 2};
  keyboard['f'] = {1, 3};
  keyboard['g'] = {1, 4};
  keyboard['h'] = {1, 5};
  keyboard['j'] = {1, 6};
  keyboard['k'] = {1, 7};
  keyboard['l'] = {1, 8};
  keyboard['z'] = {2, 0};
  keyboard['x'] = {2, 1};
  keyboard['c'] = {2, 2};
  keyboard['v'] = {2, 3};
  keyboard['b'] = {2, 4};
  keyboard['n'] = {2, 5};
  keyboard['m'] = {2, 6};
  int t;
  read(t);
  loop(t) {
    string s, s1;
    int n;
    read(s, n);
    vector<pair<int, string>> xd;
    rep(i, n) {
      read(s1);
      int dis = 0;
      rep(i, int(s1.size())) {
        dis += abs(keyboard[s1[i]].first - keyboard[s[i]].first) +
               abs(keyboard[s1[i]].second - keyboard[s[i]].second);
      }
      xd.push_back({dis, s1});
    }
    sort(xd.begin(), xd.end());
    for (auto x : xd) {
      print(x.second, x.first);
    }
  }
  return 0;
}
