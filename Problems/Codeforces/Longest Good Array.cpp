#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

ll l, r;

ll predicate(ll x){
    return (l + ((x * (x + 1)) / 2)) <= r;
}

// The last number that satisfies the predicate
ll bin_search(){
    ll lo = 0, hi = 1e9, mid;
    while(lo < hi){
        mid = lo + (hi - lo + 1) / 2;
        if(predicate(mid)) lo = mid;
        else hi = mid - 1;
    }
    return lo;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int t;
    cin >> t;
    while(t--){
        cin >> l >> r;
        cout << bin_search() + 1 << '\n';
    }

    return 0;
}