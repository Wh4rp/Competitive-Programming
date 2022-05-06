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

// Último que es mayor o igual que key

int binsearch(vector<int>& v, int key, int i, int j) {
  while (i < j) {
    int m = (i + j) >> 1;
    if (v[m] > key)
      j = m;
    else
      i = m + 1;
  }
  if (v[i] == key)
    return i;
  if (v[i - 1] == key)
    return i - 1;
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  int n, q, s;
  read(n, q);

  vector<int> v(n);
  for (auto& x : v)
    read(x);
  loop(q) {
    read(s);
    print(binsearch(v, s, 0, n - 1));
  }
  return 0;
}
