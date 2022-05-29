#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define REPGET(_1, _2, _3, NAME, ...) NAME
#define rep3(i, b, n) for (int i = b; i < n; i++)
#define rep2(i, n) rep3(i, 0, n)
#define rep(...) REPGET(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define invrep3(i, b, n) for (int i = n - 1; i >= b; i--)
#define invrep2(i, n) invrep3(i, 0, n)
#define invrep(...) REPGET(__VA_ARGS__, invrep3, invrep2)(__VA_ARGS__)

const long long MOD = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  int ones = 0;
  long long onetwopairs = 0;
  long long sets = 0;
  rep(i, n) {
    int h;
    cin >> h;
    if (h == 1) {
      ones += 1;
    } else if (h == 2) {
      onetwopairs = (onetwopairs + onetwopairs + ones) % MOD;
    } else if (h == 3) {
      sets = (sets + onetwopairs) % MOD;
    }
  }
  cout << sets << '\n';
}
