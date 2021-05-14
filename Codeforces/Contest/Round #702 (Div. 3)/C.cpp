#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < n; ++i)
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

  ll t, x, cubo;
  unordered_map<ll, bool> cubos;
  rep(i, 10001) {
    cubo = (i + 1) * (i + 1) * (i + 1);
    cubos.insert({cubo, true});
  }

  read(t);
  loop(t) {
    read(x);
    bool si = true;
    rep(i, 10001) {
      cubo = x - (i + 1) * (i + 1) * (i + 1);
      if (cubo == 0)
        continue;
      if (cubo < 0)
        break;
      if (cubos[cubo]) {
        print("YES");
        si = false;
        break;
      }
    }
    if (si)
      print("NO");
  }

  return 0;
}
