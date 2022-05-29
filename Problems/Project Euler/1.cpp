#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

int main() {
  ll sum = 0;
  rep_(i, 1, 1001){
    if(i % 3 == 0 || i % 5 == 0)
      sum += i;
  }
  cout << sum << '\n';
  return 0;
}