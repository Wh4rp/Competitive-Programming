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

  ll n, q, L, R;
  read(n);
  vector<ll> s(n), d, sum;
  for (ll& x : s)
    read(x);
  sort(s.begin(), s.end());
  rep(i, n - 1) d.push_back(s[i + 1] - s[i]);

  sort(d.begin(), d.end());
  sum.push_back(0);
  rep(i, n - 1) sum.push_back(sum[i] + d[i]);
  read(q);
  loop(q) {
    read(L, R);
    ll dif = R - L + 1;
    ll pos = lower_bound(d.begin(), d.end(), dif) - d.begin();
    cout << sum[pos] + dif * (n - pos) << " \n"[hi == (q - 1)];
  }
  return 0;
}
