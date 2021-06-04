#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string a, b;
  cin >> a >> b;
  bool suma = 0;  // si le debo sumar 1 por el anterior
  if (a.length() < b.length())
    swap(a, b);
  if (a.length() == b.length() && a < b)
    swap(a, b);

  ll ans = 0;
  ll mul = 1;
  rep(i, a.length()) {
    if (a[i] + b[i] - 2 * '0' + suma >= 10) {
      ans += (abs(a[i] - b[i]) + suma) * mul;
      suma = 1;
    } else
      suma = 0;
    mul *= 10;
  }
  cout << ans << '\n';

  return 0;
}