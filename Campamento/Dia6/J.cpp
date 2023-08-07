#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

struct Node {
    ll total, max_sum_left, max_sum_right;
    Node() {  // neutro
        total = 0LL;
        max_sum_left = 0LL;
        max_sum_right = 0LL;
    }
    Node(ll total) : total(total) {
        max_sum_left = max(0LL, total);
        max_sum_right = max(0LL, total);
    }
    Node(const Node& a, const Node& b) {
        total = a.total + b.total;
        max_sum_left = max(b.max_sum_left, b.total + a.max_sum_left);
        max_sum_right = max(a.max_sum_right, a.total + b.max_sum_right);
    }
};

// 0 - indexed / inclusive - exclusive
template <class node>
struct ST {
    vector<node> t;
    ll n;

    ST(vector<node>& arr, ll N) : n(N), t(N * 2) {
        copy(arr.begin(), arr.end(), t.begin() + n);
        for (ll i = n - 1; i > 0; --i)
            t[i] = node(t[i << 1], t[i << 1 | 1]);
    }
    void set(ll p, const node& value) {
        for (t[p += n] = value; p >>= 1;)
            t[p] = node(t[p << 1], t[p << 1 | 1]);
    }
    node query(ll l, ll r) {
        if (l < 0 || l == n)
            return Node();
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

    ll t;
    cin >> t;
    while (t--) {
        ll n, Q;
        cin >> n >> Q;
        vector<Node> v(n);
        rep(i, n) {
            ll aux;
            cin >> aux;
            v[i] = Node(aux);
        }
        ST<Node> st(v, n);
        rep(i, Q) {
            char q;
            cin >> q;
            if (q == 'U') {
                ll x;
                ll v;
                cin >> x >> v;
                x--;
                st.set(x, v);
            } else {
                ll x, y;
                cin >> x >> y;
                x--, y--;
                Node total = st.query(x, y + 1), ansl = st.query(0, x),
                     ans2 = st.query(y + 1, n);
                // cout << "Maxima suma a la izquierda que termina " << x - 1
                //      << ' ' << ansl.max_sum_left << '\n';
                // cout << "Maxima suma a la derecha que comienza en " << y + 1
                //      << ' ' << ansl.max_sum_left << '\n';
                cout << total.total + ansl.max_sum_left + ans2.max_sum_right
                     << '\n';
            }
        }
    }

    return 0;
}