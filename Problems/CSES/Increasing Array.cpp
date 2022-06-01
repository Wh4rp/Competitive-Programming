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
  
  ll n, ans = 0;
  cin >> n;
  ll nums[n];
  rep(i, n) cin >> nums[i];
  rep(i, n - 1){
    if(nums[i] > nums[i + 1]){
      ans += nums[i] - nums[i + 1];
      nums[i+1] = nums[i];
    }
  }
  cout << ans << '\n';
  
  return 0;
}