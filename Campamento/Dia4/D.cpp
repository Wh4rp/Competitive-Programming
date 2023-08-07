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

    int n, m, ans;
    cin >> n >> m;
    bool visited[200005];
    rep(i, 200005)
        visited[i] = false;
    queue<pair<int, int>> q;
    q.push({n, 0});
    visited[n] = true;
    while (!q.empty()) {
        pair<int, int> x = q.front();
        q.pop();
        if (x.first == m) {
            ans = x.second;
            break;
        }
        if (2 * x.first < 200005 && !visited[2 * x.first]) {
            q.push({2 * x.first, x.second + 1});
            visited[2 * x.first] = true;
        }
        if (x.first - 1 >= 0 && !visited[x.first - 1]) {
            q.push({x.first - 1, x.second + 1});
            visited[x.first - 1] = true;
        }
    }
    cout << ans << '\n';

    return 0;
}