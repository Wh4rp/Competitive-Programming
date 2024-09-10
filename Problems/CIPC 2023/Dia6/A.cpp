#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep_(i, k, n) for (ll i = k; i < n; ++i)
using ll = long long;

struct Node {
    ll v;
    Node() { v = -1; }  // neutro
    Node(ll v) : v(v) {}
    Node(const Node& a, const Node& b) { v = max(a.v, b.v); }
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

ll n, m;
pair<pair<ll, ll>, ll> ranas[200005];
ll x[200005], t[200005], rango[200005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    cin >> n >> m;
    // cout <<  "HOLA\n";
    ll eaten[n], tonge[n];
    rep(i, n) eaten[i] = 0;
    vector<Node> v(n);
    // cout <<  "HOLA\n";
    rep(i, n) {
        cin >> ranas[i].first.first >> ranas[i].first.second;
        tonge[i] = ranas[i].first.second;
        ranas[i].second = i;
        // cin >> ranas[i].first.first >> ranas[i].first.second;
        // v[i] = Node(ranas[i].first.first + ranas[i].first.second);
    }
    sort(ranas, ranas + n);
    rep(i, n) {
        v[i] = Node(ranas[i].first.first + ranas[i].first.second);
    }

    ST<Node> st(v, n);

    set<pair<ll, ll>> to_eat, curr_eating;

    rep(k, m) {
        ll p, b;
        cin >> p >> b;
        to_eat.insert({p, b});

        ll mid, i = 0, j = n - 1;
        while (i < j) {
            ll mid = (i + j) / 2;
            if (st.query(0, mid + 1).v >= p)
                j = mid;
            else
                i = mid + 1;
        }
        for (auto pos = to_eat.find({p, b}); pos != to_eat.end();
             pos++) {
            ll p1 = (*pos).first, b1 = (*pos).second;
            // cout <<  "La rana " << i << " con posicion " <<
            // ranas[i].first.first
            //      << " alcance hasta "
            //      << ranas[i].first.first + ranas[i].first.second
            //      << " se llenta comer a la mosca " << p1 << ' ' << b1 <<
            //      '\n';

            if (ranas[i].first.first <= p1 &&
                p1 <= ranas[i].first.first + ranas[i].first.second) {
                // cout <<  "COME" << '\n';
                eaten[ranas[i].second]++;
                tonge[ranas[i].second] += b1;
                ranas[i].first.second += b1;
                st.set(i, ranas[i].first.first + ranas[i].first.second);
                curr_eating.insert({p1, b1});
            } else
                break;
        }
        for (auto mosca : curr_eating)
            to_eat.erase(mosca);
    }

    rep(i, n) {
        cout << eaten[i] << ' ' << tonge[i] << '\n';
    }

    return 0;
}