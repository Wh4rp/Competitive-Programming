#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    set<int> cards;
    rep(i, 4) {
        int x;
        cin >> x;
        cards.insert(x);
    }

    if(cards.size() == 2) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}