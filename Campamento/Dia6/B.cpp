#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

struct Node {
    ll v, deep;
    Node() {  // neutro
        v = 0;
        deep = -1;
    }
    Node(ll v) : v(v), deep(0) {}
    Node(const Node& a, const Node& b) {
        if (max(a.deep, b.deep) % 2)
            v = a.v ^ b.v;
        else
            v = a.v | b.v;
        deep = max(a.deep, b.deep) + 1;
    }
};

// 0 - indexed / inclusive - exclusive
template <class node>
struct ST {
    vector<node> t;
    int n;

    ST(vector<node>& arr, int N) : n(N), t(N * 2) {
        copy(arr.begin(), arr.end(), t.begin() + n);
        for (int i = n - 1; i > 0; --i)
            t[i] = node(t[i << 1], t[i << 1 | 1]);
    }
    void set(int p, const node& value) {
        for (t[p += n] = value; p >>= 1;)
            t[p] = node(t[p << 1], t[p << 1 | 1]);
    }
    node query(int l, int r) {
        node ansl, ansr;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                ansl = node(ansl, t[l++]);
            if (r & 1)
                ansr = node(t[--r], ansr);
        }
        return node(ansl, ansr);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int n, q;
    cin >> n >> q;
    ll N = 1;
    rep(i, n) N *= 2;
    vector<Node> v(N);
    rep(i, N) {
        ll x;
        cin >> x;
        v[i] = Node(x);
    }
    ST<Node> st(v, N);
    rep(i, q) {
        ll p, b;
        cin >> p >> b;
        st.set(p - 1, b);
        cout << st.query(0, N).v << '\n';
    }
    return 0;
}