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

bool seen[256];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  bool ok = true;
  while (true) {
    char c;
    if (!(cin >> c)) {
      break;
    }
    if (c < 'a' || c > 'z') {
      continue;
    }
    if (seen[c]) {
      ok = false;
    } else {
      seen[c] = true;
    }
  }
  cout << ok << '\n';
}
