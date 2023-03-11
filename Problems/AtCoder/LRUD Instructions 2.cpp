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

    set<pair<int, int>> s = {{0, 0}};
    int n;
    string path;
    cin >> n >> path;
    pair<int, int> position = {0, 0};
    rep(i, n) {
        switch (path[i]) {
            case 'R':
                position.first++;
                break;
            case 'L':
                position.first--;
                break;
            case 'U':
                position.second++;
                break;
            case 'D':
                position.second--;
                break;
            default:
                break;
        }
        s.insert(position);
    }
    cout << (s.size() != n + 1? "Yes" : "No") << '\n';

    return 0;
}