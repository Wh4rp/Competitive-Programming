#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);

  int n, sol = 0;
  string s;
  cin >> n >> s;
  rep_(i, 1, n + 1) {
    if (s[i] == s[i - 1])
      sol++;
  }
  cout << sol << '\n';
  return 0;
}
