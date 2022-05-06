#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
#define loop(h) for (int hi = 0; hi < h; hi++)
#define ii pair<int, int>
using ll = long long;

template <typename First>
bool read(First& t) {
  if (cin >> t)
    return true;
  return false;
}
template <typename First, typename... Args>
bool read(First& f, Args&... args) {
  cin >> f;
  return read(forward<Args&>(args)...);
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
  ll t, N, W, L;
  read(t);
  loop(t) {
    read(N, W, L);
    vector<ll> v(W);
    for (ll& x : v)
      read(x);
    if (L == 1) {
      print(N);
      continue;
    }
    ll l = 1, r = N, largo_max;
    while (l < r) {
      largo_max = (l + r) >> 1;
      ll bagones_necesarios = 0;
      ll start = 1, end = min(largo_max, N);
      if (v[0] > largo_max) {
        start = v[0];
        end = min(start + largo_max - 1, N);
        bagones_necesarios++;
      }
      rep(i, W) {
        if (end < v[i]) {
          if (v[i] <= end + largo_max) {
            start = end + 1;
            end = min(end + largo_max, N);
            bagones_necesarios++;
          } else {
            start = v[i];
            end = min(start + largo_max - 1, N);
            bagones_necesarios += 2;
          }
        }
        if (bagones_necesarios >= L)
          break;
      }
      bagones_necesarios += 1 + (end != N);
      if (bagones_necesarios <= L)
        r = largo_max;
      else
        l = largo_max + 1;
    }
    print(r);
  }
  return 0;
}