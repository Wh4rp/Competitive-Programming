#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

#include "../Template.cpp"

int n;
vector<ll> a(1e5 + 5);
string s;

struct Node
{
    int v, active, lzv = 0;
    bool base = false;
    bool lz = false;
    Node() : v(0) {}
    Node(int x, int pos) {
        v = x;
        base = true;
        active = s[pos] - '0';
    }
    Node(const Node &a, const Node &b){
        int val_a = a.v, val_b = b.v;
        if(a.base) v = val_a * a.active;
        if(b.base) v = val_b * b.active;
        v = val_a ^ val_b;
    }
    Node(int x, int i, int j, const Node &b)
    {
        
    }
};

// 0 - indexed / inclusive - inclusive
template <class node>
struct STL
{
    vector<node> st; int n;

    void build(int u, int i, int j, vector<node> &arr)
    {
        if (i == j) { st[u] = arr[i]; return; }
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        build(l, i, m, arr), build(r, m + 1, j, arr);
        st[u] = node(st[l], st[r]);
    }
    void push(int u, int i, int j, int x)
    {
        st[u] = node(x, i, j, st[u]);
        if (i == j) return;
        st[u * 2 + 1].lz = 1, st[u * 2 + 1].lzv += x;
        st[u * 2 + 2].lz = 1, st[u * 2 + 2].lzv += x;
    }
    node query(int a, int b, int u, int i, int j)
    {
        if (j < a || b < i) return node();
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (st[u].lz) push(u, i, j, st[u].lzv);
        if (a <= i && j <= b) return st[u];
        return node(query(a, b, l, i, m), query(a, b, r, m + 1, j));
    }
    void update(int a, int b, int v, int u, int i, int j)
    {
        if (st[u].lz) push(u, i, j, st[u].lzv);
        if (j < a || b < i) return;
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (a <= i && j <= b) { push(u, i, j, v); return; }
        update(a, b, v, l, i, m); update(a, b, v, r, m + 1, j);
        st[u] = node(st[l], st[r]);
    }

    STL(vector<node> &v, int N) : n(N), st(N * 4 + 5) { build(0, 0, n - 1, v); }
    node query(int a, int b) { return query(a, b, 0, 0, n - 1); }
    void update(int a, int b, int v) { update(a, b, v, 0, 0, n - 1); }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    

    return 0;
}