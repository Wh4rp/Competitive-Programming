#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

struct bounds {
  ll t, l, r;
};


bool inter(bounds a, bounds b){
  if (a.r < b.l || b.r < a.l)
    return false;
  if(a.r == b.l && ((a.t != 1 && a.t != 3) || (b.t != 1 && b.t != 2)) )
    return false;
  swap(a, b);
  if(a.r == b.l && ((a.t != 1 && a.t != 3) || (b.t != 1 && b.t != 2)) )
    return false;
  
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  
  int n, sol = 0, t, l, r;
  cin >> n;
  vector<bounds> v(n);
  for(auto& x : v){
    cin >> t >> l >> r;
    x.t = t;
    x.l = l;
    x.r = r;
  }
  rep(i, n - 1){
    rep_(j, i + 1, n)
      if(inter(v[i], v[j])){
        sol++;
      }
  }

  cout << sol << "\n";
  
  return 0;
}