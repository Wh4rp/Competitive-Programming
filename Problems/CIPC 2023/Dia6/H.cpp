#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

struct Node {
    int v, min_acc_sum;
    bool balanced;
    Node() {  // neutro
        v = 0;
        balanced = true;
        min_acc_sum = 0;
    }
    Node(char c) {
        balanced = false;
        if (c == '(') {
            v = 1;
            min_acc_sum = 1;
        } else {
            v = -1;
            min_acc_sum = -1;
        }
    }
    Node(const Node& a, const Node& b) {
        v = a.v + b.v;
        min_acc_sum = min(a.min_acc_sum, a.v + b.min_acc_sum);
        balanced = ((v == 0) && min_acc_sum >= 0);
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
    string t;
    cin >> n >> q >> t;
    vector<char> s(n);
    rep(i, n) s[i] = t[i];
    vector<struct Node> v(n);
    rep(i, n) v[i] = Node(s[i]);

    ST<Node> st(v, n);

    // cout << st.query(0, n).v << '\n';
    // cout << st.query(0, n - 1).v << '\n';
    // cout << st.query(0, n - 2).v << '\n';
    // cout << st.query(0, n - 3).v << '\n';
    // cout << st.query(0, n - 4).v << '\n';
    // cout << st.query(l, r).v << '\n';
    // cout << st.query(l, r).v << '\n';
    rep(i, q) {
        int x, l, r;
        cin >> x >> l >> r;
        l--, r--;
        if (x == 1) {
            swap(s[l], s[r]);
            st.set(l, Node(s[l]));
            st.set(r, Node(s[r]));
        } else {
            // cout << "\n-------\n";
            Node ans = st.query(l, r + 1);
            // rep_(i, l, r + 1) cout << t[i];
            // cout << '\n';
            // cout << "val: " << ans.v << '\n';
            // cout << "balanced: " << ans.balanced << '\n';
            // cout << "Min accumulate sum: " << ans.min_acc_sum << '\n';
            if (ans.balanced)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }

    return 0;
}