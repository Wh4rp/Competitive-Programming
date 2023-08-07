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

    int n, Q;
    cin >> n >> Q;
    set<int> called;

    int first = 1;

    rep(i, Q) {
        int q;
        cin >> q;
        if (q == 1) {
            if (first > n)
                continue;
            called.insert(first);
            first++;
        } else if (q == 2) {
            int x;
            cin >> x;
            called.erase(x);
        } else {
            cout << *called.begin() << '\n';
        }
    }

    return 0;
}