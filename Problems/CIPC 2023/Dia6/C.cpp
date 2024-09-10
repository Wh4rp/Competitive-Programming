#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

struct Node {
    ll v1, v2;
    Node() { v1 = 0, v2 = 0; }  // neutro
    Node(int v) : v1(v), v2(0) {}
    Node(const Node& a, const Node& b) {
        int v[] = {a.v1, a.v2, b.v1, b.v2};
        sort(v, v + 4);
        v1 = v[3];
        v2 = v[2];
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

    int n;
    cin >> n;
    vector<Node> v(n);
    rep(i, n) {
        ll aux;
        cin >> aux;
        v[i] = Node(aux);
    }
    ST<Node> st(v, n);
    int Q;
    cin >> Q;
    rep(j, Q) {
        char q;
        cin >> q;
        if (q == 'U') {
            int i, x;
            cin >> i >> x;
            i--;
            st.set(i, x);
        } else {
            int x, y;
            cin >> x >> y;
            x--, y--;
            Node ans = st.query(x, y + 1);
            cout << ans.v1 + ans.v2 << '\n';
        }
    }

    return 0;
}