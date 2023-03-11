#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

bool cmp(pair<int, int> x, pair<int, int> y) {
    if (x.first != y.first)
        return x.first < y.first;
    else
        return x.second > y.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> versus;
        int aux, pts[n];
        rep(i, n) {
            cin >> aux;
            versus.push_back({aux, i});
            pts[i] = i + 1;
        }
        sort(versus.begin(), versus.end(), cmp);
        int k = 0, wins = 0;
        for (auto vs : versus) {
            if (k + vs.first > m) {
                break;
            } else {
                k += vs.first;
                wins++;
                pts[vs.second]--;
            }
        }
        if (wins > pts[n - 1]) {
            cout << 1 << '\n';
        } else {
            cout << count_if(pts, pts + n, [&](int x) { return x > wins; }) + 1
                 << '\n';
        }
    }

    return 0;
}