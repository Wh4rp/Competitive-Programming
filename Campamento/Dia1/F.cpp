#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;
using db = double;

const db PI = acos(-1.0L);
const db EPS = 1e-12;

// POINT 2D

typedef db T;
struct P {
    T x, y;
    P() {}
    P(T x, T y) : x(x), y(y) {}

    P operator+(const P& p) const { return P(x + p.x, y + p.y); }
    P operator-(const P& p) const { return P(x - p.x, y - p.y); }
    P operator*(const db& c) const { return P(x * c, y * c); }
    P operator/(const db& c) const { return P(x / c, y / c); }
    T operator^(const P& p) const { return x * p.y - y * p.x; }
    T operator*(const P& p) const { return x * p.x + y * p.y; }
    bool operator==(const P& p) const {
        return abs(x - p.x) + abs(y - p.y) < EPS;
    }
    bool operator<(const P& p) const {
        return abs(x - p.x) > EPS ? p.x - x > EPS : p.y - y > EPS;
    }

    T norm2() const { return x * x + y * y; }
    db norm() const { return sqrt(norm2()); }
    db ang() {
        db a = atan2(y, x);
        if (a < 0)
            a += 2. * PI;
        return a;
    }
    P unit() { return (*this) / norm(); }
    P perp() { return P(-y, x); }
    P rot(P r) { return P((*this) ^ r, (*this) * r); }
    P rot(db a) { return rot(P(sin(a), cos(a))); }
};
P polar(db r, db a) {
    return P(r * cos(a), r * sin(a));
}
istream& operator>>(istream& s, P& p) {
    return s >> p.x >> p.y;
}
ostream& operator<<(ostream& s, const P& p) {
    return s << '(' << p.x << ", " << p.y << ')';
}

db ang(db a) {
    while (a >= 2. * PI)
        a -= 2. * PI;
    while (a < 0)
        a += 2. * PI;
    return a;
}

T turn(P& a, P& b, P& c) {
    return (b - a) ^ (c - a);
}

bool half(P& p) {
    return p.y > 0 || (p.y == 0 && p.x > 0);
}

void polarSort(vector<P>& v) {
    sort(v.begin(), v.end(), [](P& p1, P& p2) {
        int h1 = half(p1), h2 = half(p2);
        return h1 != h2 ? h1 > h2 : (p1 ^ p2) > 0;
    });
}

// LINE

struct L {
    P v;
    T c;
    L() {}
    L(P v, T c) : v(v), c(c) {}
    L(T a, T b, T c) : v(P(b, -a)), c(c) {}
    L(P p, P q) : v(q - p), c(v ^ p) {}

    T side(P p) { return (v ^ p) - c; }
    db dist(P p) { return abs(side(p) / v.norm()); }
    db dist2(P p) { return side(p) * side(p) / (db)v.norm2(); }
    L perp(P p) { return L(p, p + v.perp()); }
    L translate(P t) { return L(v, c + (v ^ t)); }
    P proj(P p) { return p - v.perp() * side(p) / v.norm2(); }
    P refl(P p) { return p - v.perp() * 2 * side(p) / v.norm2(); }
};

bool parallel(L l1, L l2) {
    return abs(l1.v ^ l2.v) < EPS;
}

db lm, lg;

bool fun(db Ax, db Ay, db Bx, db By, db Cx, db Cy) {
    P p1(Ax, Ay), p2(Bx, By), p3(Cx, Cy);

    db d1 = (p1 - p2).norm(), d2 = (p1 - p3).norm(), d3 = (p2 - p3).norm();

    L l1(p1, p2), l2(p1, p3);

    if (parallel(l1, l2) && max({d1, d2, d3}) - EPS <= max(lm, 2 * lg)) {
        return true;
    }

    L l(p1, p2);

    if (l.dist(p3) > lm + EPS || (p1 - p2).norm() > 2 * lg + EPS) {
        return false;
    }
    P proj = l.proj(p3);

    if ((p1 - proj).norm() > lg + EPS || (p2 - proj).norm() > lg + EPS) {
        return false;
    }

    return true;
}

bool fun2(db Ax, db Ay, db Bx, db By, db Cx, db Cy) {
    P p1(Ax, Ay), p2(Bx, By), p3(Cx, Cy);
    L l(p1, p2);
    P proj = l.proj(p3);
    db d = (p1 - p2).norm();
    db dp1proj = (p1 - proj).norm();
    db dp2proj = (p2 - proj).norm();
    db dp3proj = (p3 - proj).norm();
    if (d > lm || max(dp1proj, dp2proj) > lm || dp3proj > lg)
        return false;
    if (((p1 - p3) ^ (proj - p3)) * ((p2 - p3) ^ (proj - p3)) < 0) {
        return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int t;
    cin >> t;
    while (t--) {
        cin >> lm >> lg;
        db Ax, Ay;
        db Bx, By;
        db Cx, Cy;
        cin >> Ax >> Ay;
        cin >> Bx >> By;
        cin >> Cx >> Cy;
        if (fun(Ax, Ay, Bx, By, Cx, Cy) || fun(Ax, Ay, Cx, Cy, Bx, By) ||
            fun(Bx, By, Cx, Cy, Ax, Ay) || fun2(Ax, Ay, Bx, By, Cx, Cy) ||
            fun2(Ax, Ay, Cx, Cy, Bx, By) || fun2(Bx, By, Cx, Cy, Ax, Ay)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}