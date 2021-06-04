#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repx(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;

int n;
vector<int> A;

bool funcion(int i, int j, int m) {
  int mini = A[m - 1] - A[i];
  int maxi = A[i] + A[j];
  if (mini < A[m] && A[m] < maxi)
    return true;
  else
    return false;
}

int BB(int i, int j) {
  int l = j, r = n;
  while (l < r) {
    int m = (l + r) / 2;
    if (!funcion(i, j, m))
      r = m;
    else
      l = m + 1;
  }

  return l - 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  A.resize(n);
  for (int& x : A)
    cin >> x;

  sort(A.begin(), A.end());
  ll ans = 0;
  A.push_back(0);
  rep(i, n - 2) {
    repx(j, i + 1, n - 1) {
      ll aux = BB(i, j) - (j);
      ans += ((1LL) << aux) - 1;
    }
  }
  cout << ans << "\n";
  return 0;
}