#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep_(i, k, n) for (ll i = k; i < n; ++i)
using ll = long long;

set<pair<ll, ll>> casas_x;

// set order by second
struct cmp {
    bool operator()(const pair<ll, ll>& a, const pair<ll, ll>& b) const {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    }
};

set<pair<ll, ll>, cmp> casas_y;

ll check(ll x1, ll y1, ll x2, ll y2) {
    // cout << x1 << ' ' << y1 << " -> " << x2 << ' ' << y2 << '\n';
    vector<pair<ll, ll>> casas;
    if(x1 == x2) {
        ll a = min(y1, y2), b = max(y1, y2);
        auto pos = casas_x.lower_bound({x1, a});
        while(pos != casas_x.end()) {
            // cout << "Casa: " << (*pos).first << ' ' << (*pos).second << '\n';
            if((*pos).first != x1) break;
            if((*pos).second > b) break;
            casas.push_back(*pos);
            pos = next(pos, 1);
        }
    } else {
        ll a = min(x1, x2), b = max(x1, x2);
        auto pos = casas_y.lower_bound({a, y1});
        while(pos != casas_y.end()) {
            // cout << "Casa: " << (*pos).first << ' ' << (*pos).second << '\n';
            if((*pos).second != y1) break;
            if((*pos).first > b) break;
            casas.push_back(*pos);
            pos = next(pos, 1);
        }
    }

    ll ans = casas.size();

    for(auto casa : casas) {
        // cout << "Eliminamos " << casa.first << ' ' << casa.second << '\n';
        casas_x.erase(casa);
        casas_y.erase(casa);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    ll n, m, x, y, ans = 0;
    cin >> n >> m >> x >> y;

    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        casas_x.insert({a, b});
        casas_y.insert({a, b});
    }

    rep(i, m) {
        char move;
        ll len;
        cin >> move >> len;
        if(move == 'U'){
            ans += check(x, y, x, y + len);
            x = x, y = y + len;
        } else if(move == 'D'){
            ans += check(x, y, x, y - len);
            x = x, y = y - len;
        } else if(move == 'L'){
            ans += check(x, y, x - len, y);
            x = x - len, y = y;
        } else if(move == 'R'){
            ans += check(x, y, x + len, y);
            x = x + len, y = y;
        }
    }

    cout << x << ' ' << y << ' ' << ans << '\n';

    return 0;
}