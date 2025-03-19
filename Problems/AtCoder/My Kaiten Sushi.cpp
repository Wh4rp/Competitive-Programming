#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

struct Node {
    pair<int, int> v;
    Node() { v = {0, -1}; }           // neutro
    Node(pair<int, int> v) : v(v) {}  // Node a(10); -> a.v := 10
    Node(const Node& a, const Node& b) {
        if (a.v.first > b.v.first) {
            v = a.v;
        } else if (a.v.first < b.v.first) {
            v = b.v;
        } else if (a.v.first == b.v.first) {
            v = {a.v.first, min(a.v.second, b.v.second)};
        }
    }
};

// 0 - indexed / inclusive - exclusive
// ST query(0, 10) -> [0, 10)
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

int bs(ST<Node>& st, int n, int key) {
    int i = 0, j = n - 1;
    while (i < j) {
        int m = (i + j) / 2;
        // cout << "m: " << m << '\n';
        // cout << st.query(0, m + 1).v.second << '\n';
        if (key <= st.query(0, m + 1).v.first)
            j = m;
        else
            i = m + 1;
    }
    return i;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int n, m;
    cin >> n >> m;

    int a[n], b[m];

    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    vector<Node> v;

    rep(i, m) {
        v.push_back(Node({b[i], i}));
    }

    ST<Node> st(v, m);

    int ans[n];

    cout << bs(st, m, 2) << '\n';

    rep(i, n) {
        ans[i] = bs(st, m, a[i]);
        // cout << i << ": " << ans[i] << '\n';
        if(b[ans[i]] >= a[i]){
            st.set(ans[i], Node({0, -1}));
        } else {
            ans[i] = -1;
        }
    }

    int ans2[m];

    memset(ans2, -1, sizeof(ans2));

    rep(i, n) {
        cout << i << ": " << ans[i] << '\n';
    }

    rep(i, n) {
        if(ans[i] != -1){
            ans2[ans[i]] = i + 1;
        }
    }


    rep(i, m) {
        cout << ans2[i] << '\n';
    }

    return 0;
}