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

ll gcd(ll a, ll b) {
  return b ? gcd(b, a % b) : a;
}

ll sumgcd(ll x) {
  ll n = 0;
  string s = to_string(x);
  rep(i, int(s.length())) n += s[i] - 48;
  return gcd(x, n);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  ll t, x;
  read(t);
  loop(t) {
    read(x);
    while (sumgcd(x) == 1) {
      x++;
    }
    print(x);
  }

  return 0;
}
