#include <bits/stdc++.h>
using namespace std;
#define rep_(i, b) for(int i = 0; i < b; ++i)
#define rep(i,a,b) for(int i = a; i <= b; ++i)
#define invrep(i,b,a) for(int i = b; i >= a; --i)
typedef long long int ll;
// ----------------------------------------------
// Caja negra de apuntes de Pablo
// ----------------------------------------------
struct Point {
    ll x, y;
    ll operator^(const Point& p) const { return x*p.y - y*p.x; }
    bool operator<(const Point& p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
    Point operator-(const Point& p) const{
    	return Point({x - p.x, y - p.y});
    }
};
ll turn(Point& a, Point& b, Point& c) { return (b-a)^(c-a); }

double dis(Point& a, Point& b){
	ll difx = a.x - b.x, dify = a.y - b.y;
	return sqrt(difx*difx + dify*dify);
}

vector<Point> convex_hull(vector<Point>& P) {
    int n = P.size(), k = 0;
    // set initial capacity
    vector<Point> H(2*n);
    // sort points lexicographically
    sort(P.begin(), P.end());
    // build lower hull
    for (int i = 0; i < n; ++i) {
        while (k >= 2 && turn(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    // build upper hull
    for (int i = n-2, t = k+1; i >= 0; i--) {
        while (k >= t && turn(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    // remove extra space
    H.resize(k-1);
    return H;
}

int main(){
	vector<Point> puntosxd;
	int N, L, x, y;
	cin >> N >> L;

	rep_(i, N){
		cin >> x >> y;
		puntosxd.push_back({x, y});
	}

	auto puntos_convexos = convex_hull(puntosxd);

	puntos_convexos.push_back(puntos_convexos[0]);

	double per = 0;

	rep_(i, puntos_convexos.size() - 1){
		per += dis(puntos_convexos[i], puntos_convexos[i + 1]);
	}
	per += 2 * L * 3.141592653589;

	cout << round(per) << '\n';
	return 0;
}