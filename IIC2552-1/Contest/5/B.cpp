#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)

int a[10], v[10], k, sum;

bool bt(int l){
  if(sum > k)
    false;
  if (l == 10){
    if(sum <= k){
      rep(i, 10){
        cout << v[i] << ' ';
      }
      cout << '\n';
      return true;
    }
    else
      return false;
  }
  else{
    rep_(i, l, 10){
      
      swap(v[l], v[i]);
      sum += v[l] * a[l];
      if(bt(l+1))
        return true;
      sum -= v[l] * a[l];
      swap(v[l], v[i]);
    }
    return false;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);

  int t;
  cin >> t;
  while(t--){
    sum = 0;
    rep(j, 10)
      v[j] = j;
    rep(i, 10)
      cin >> a[i];
    cin >> k;
    if(!bt(0)){
      cout << "-1\n";
    }
  }
  
  return 0;
}