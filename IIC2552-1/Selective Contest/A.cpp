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
  ll n, sum = 0, maxi = 0, sum1 = 0;
  read(n);
  vector<ll> v(n);
  for (ll& x : v) {
    read(x);
    sum += x;
    maxi = max(maxi, x);
  }
  sum1 = n * maxi - sum;
  ll l = maxi, r = 202;
  if (maxi > sum) {
    print(maxi);
    return 0;
  }

  while (l < r) {
    ll m = (l + r) >> 1;
    if (sum1 + (m - maxi) * n > sum)
      r = m;
    else
      l = m + 1;
  }
  print(r);
  return 0;
}