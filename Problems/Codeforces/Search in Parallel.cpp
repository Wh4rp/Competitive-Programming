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

    int t;
    cin >> t;
    while (t--) {
        int n, s1, s2;
        cin >> n >> s1 >> s2;
        pair<int, int> boxes[n];
        rep(i, n) {
            cin >> boxes[i].first;
            boxes[i].second = i + 1;
        }
        sort(boxes, boxes + n, greater<pair<int, int>>());
        vector<int> a, b;
        ll lenA = 0, lenB = 0;
        rep(i, n) {
            if (((lenA + 1) * boxes[i].first * s1) <
                ((lenB + 1) * boxes[i].first * s2)) {
                lenA++;
                a.push_back(boxes[i].second);
            } else {
                lenB++;
                b.push_back(boxes[i].second);
            }
        }

        cout << lenA << ' ';
        for (int i : a) {
            cout << i << ' ';
        }
        cout << '\n';
        cout << lenB << ' ';
        for (int i : b) {
            cout << i << ' ';
        }
        cout << '\n';
    }

    return 0;
}