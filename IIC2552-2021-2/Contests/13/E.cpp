#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

ll gcd (ll a, ll b) {
    while (b) { a %= b; swap(a,b); }
    return a;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  
  ll xb, yb, x1, y1, x2, y2;
  cin >> xb >> yb >> x1 >> y1 >> x2 >> y2;


  ll xp = xb / gcd(xb, yb), yp = yb / gcd(xb, yb);

  if(x1 <= xp && xp <= x2 && y1 <= yp && yp <= y2){
  	ll m = min(x2 / xp, y2 / yp) + 1;
  	if(xp * m < xb && yp * m < yb){
  		cout << "No\n";
  		cout << xp * m << ' ' << yp * m << '\n';
  	}
  	else{
  		cout << "Yes\n";
  	}
  }
  else{
  	if(xp == xb && yp && yb){
  		cout << "Yes\n";
  	}
  	else{
  		cout << "No\n";
  		cout << xp << ' ' << yp << '\n';
  	}
  }

  return 0;
}