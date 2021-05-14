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

int moves1[] = {1, -1, 0, 0};
int moves2[] = {0, 0, 1, -1};

vector<string> v;
bool visitado[100][100];
ll n, m;
void dfs(ll i, ll j) {
  visitado[i][j] = true;
  rep(k, 4) {
    int i_ = i + moves1[k];
    int j_ = j + moves2[k];
    if (0 <= i_ && i_ < n && 0 <= j_ && j_ < m && v[i_][j_] == '-' &&
        !visitado[i_][j_]) {
      dfs(i_, j_);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  ll caso = 0;
  string s;
  while (cin >> n >> m) {
    v.resize(n);
    for (auto& x : v)
      read(x);
    rep(i, n) {
      rep(j, m) { visitado[i][j] = false; }
    }
    int sol = 0;

    rep(i, n) {
      rep(j, m) {
        if (!visitado[i][j] && v[i][j] == '-') {
          dfs(i, j);
          sol++;
        }
      }
    }

    cout << "Case " << ++caso << ": " << sol << '\n';
  }
  return 0;
}
