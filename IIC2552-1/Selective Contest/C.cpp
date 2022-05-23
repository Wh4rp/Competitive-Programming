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
  ll n;
  string s1, t1;

  read(n, s1, t1);
  vector<char> s(n), t(n);
  if (s1 == t1)
    print(0);
  else {
    vector<ll> sol;
    ll index = 0;
    for (char& x : s) {
      x = s1[index];
      index++;
    }
    index = 0;
    for (char& x : t) {
      x = t1[index];
      index++;
    }

    rep(i, n) {
      if (s[i] != t[i]) {
        ll pos = -1;
        rep_(j, i, n) {
          if (s[j] == t[i]) {
            pos = j;
            break;
          }
        }
        if (pos == -1) {
          print(-1);
          return 0;
        } else {
          for (int k = pos; k > i; k--) {
            sol.push_back(k);
            swap(s[k - 1], s[k]);
          }
        }
      }
    }

    ll largo = ll(sol.size());
    if (largo > 10000) {
      print(-1);
    } else {
      print(largo);
      rep(i, largo) { cout << sol[i] << " \n"[i == largo - 1]; }
    }
  }

  return 0;
}