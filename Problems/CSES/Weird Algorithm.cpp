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
  
  ll n;
  cin >> n;
  while(n!=1){
    cout << n << " ";
    if(n%2==0){
      n/=2;
    }
    else{
      n = 3 * n + 1;
    }
  }
  cout << n << endl;
  
  return 0;
}