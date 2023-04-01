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

    int n, k1, k2, aux;
    cin >> n;

    cin >> k1;
    deque<int> v1;

    rep(i, k1) {
        cin >> aux;
        v1.emplace_back(aux);
    }
    cin >> k2;
    deque<int> v2;

    rep(i, k2) {
        cin >> aux;
        v2.emplace_back(aux);
    }

    map<pair<deque<int>, deque<int>>, bool> seen;
    int ans = 0;
    while (!v1.empty() && !v2.empty()) {
        ans++;
        int val1 = v1.front();
        int val2 = v2.front();
        v1.pop_front();
        v2.pop_front();
        if (val1 > val2) {
            v1.emplace_back(val2);
            v1.emplace_back(val1);
        } else {
            v2.emplace_back(val1);
            v2.emplace_back(val2);
        }
        if (seen[{v1, v2}] == true){
            cout << "-1\n";
            return 0;
        }
        else{
            seen[{v1, v2}] = true;
        }
    }

    cout << ans << ' ';
    if (v1.empty()) {
        cout << "2\n";
    } else {
        cout << "1\n";
    }

    return 0;
}