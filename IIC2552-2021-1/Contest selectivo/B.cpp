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

  ll n, C, sum = 0, cont = 0, aux1, aux2;
  read(n, C);
  vector<ll> v(n);
  rep(i, n) {
    read(aux1, aux2);
    v[i] = aux1 - aux2;
    sum += aux1;
  }
  if (sum <= C) {
    print(0);
    return 0;
  }
  sort(v.begin(), v.end(), greater<ll>());
  for (ll x : v) {
    cont++;
    sum -= x;

    if (sum <= C) {
      print(cont);
      return 0;
    }
  }
  print(-1);
  return 0;
}