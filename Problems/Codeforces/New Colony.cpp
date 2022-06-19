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
  int t, n, k, l, pos;
  cin >> t;
  while(t--) {
    cin >> n >> k;
    vector<int> mounts(n);
    rep(i, n) 
      cin >> mounts[i];
    l = 0;
    int j = 0;
    while(l < k && j < n - 1) {
      while(j < n - 1 && mounts[j] >= mounts[j + 1])
        j++;
      mounts[j]++;
      if(j != n -1 && l < k - 1){
        j--;
      }
      l++;
    }
    if(j == n - 1)
      cout << "-1\n";
    else
      cout << j + 1 << '\n';
  }

  return 0;
}
