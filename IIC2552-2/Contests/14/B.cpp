#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

inline ll mod(ll x, ll m) { return ((x %= m) < 0) ? x+m : x; }
inline ll mul(ll x, ll y, ll m) { return (x * y) % m; }
inline ll add(ll x, ll y, ll m) { return (x + y) % m; }

ll gcdext(ll a, ll b, ll& x, ll& y) {
    ll r2, x2, y2, r1, x1, y1, r0, x0, y0, q;
    r2 = a, x2 = 1, y2 = 0;
    r1 = b, x1 = 0, y1 = 1;
    while (r1) {
        q = r2 / r1;
        r0 = r2 % r1;
        x0 = x2 - q * x1;
        y0 = y2 - q * y1;
        r2 = r1, x2 = x1, y2 = y1;
        r1 = r0, x1 = x0, y1 = y0;        
    }
    ll g = r2; x = x2, y = y2;
    if (g < 0) g = -g, x = -x, y = -y; // make sure g > 0

    return g;
}

pair<ll,ll> CRT(ll r1, ll m1, ll r2, ll m2) {
    ll g, x, y; g = gcdext(m1, m2, x, y);
    if ((r1 - r2) % g != 0) return {-1, -1}; // no solution
    ll z = m2/g;
    ll lcm = m1 * z;
    ll sol = add(mod(r1, lcm), m1*mul(mod(x,z),mod((r2-r1)/g,z),z), lcm);

    return {sol, lcm}; // solution + lcm(m1,m2)
}

int fun(int x, int n){
	if(x == n)
		return 0;
	if (x == 0 )
	{
		return n;
	}
	return x = (x + 2 * (n - x)) % n;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  
  int n, m, x, y, vx, vy;
  cin >> n >> m >> x >> y >> vx >> vy;

  int csolx[] = {0, n}, csoly[] = {0, m};

  if(vy == 0 && (y == 0 || y == m)){
  	cout << csolx[vx > 0] << ' ' << y << '\n';
  	return 0;
  }

  if(vx == 0 && (x == 0 || x == m)){
  	cout << x << ' ' << csoly[vy > 0] << '\n';
  	return 0;
  }

  if(vx == 0 || vy == 0){
		cout << "-1\n";
		return 0;
  }
  	
	if(vx < 0)
		x = fun(x, n);
	
	if(vy < 0)
		y = fun(y, m);
	
	int dx = n - x, dy = m - y;
	auto sol = CRT(dx, n, dy, m);

	if(sol.first == -1 && sol.second == -1){
	  	cout << "-1\n";
	}
	else{
		cout << csolx[((x + sol.first) / n + (vx < 0)) % 2] << ' ';
		cout << csoly[((y + sol.first) / m + (vy < 0)) % 2] << '\n';
	}

  return 0;
}