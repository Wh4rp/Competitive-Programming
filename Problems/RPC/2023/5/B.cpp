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

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    priority_queue<pair<int, int>> q;
    vector<bool> deleted(n + 1, false);
    rep(i, n) {
        cin >> v[i];
        q.push({v[i], i});
    }
    int ans = 0;
    bool flag = true;
    rep(i, n - 1) {
        if (v[i] > v[i + 1]) {
            flag = false;
            break;
        }
    }
    if (!flag) {
        while (true) {
            // eliminamos los primeros k
            rep(i, k - 1) {
                if (!q.empty()) {
                    int id = q.top().second;
                    q.pop();
                    deleted[id] = true;
                    cout << "se elimina al " << v[id] << '\n';
                } else
                    break;
            }
            flag = true;
            int prev = 0;
            rep(i, n) {
                if (!deleted[i]) {
                    cout << v[i] << ' ';
                }
            }
            cout << '\n';
            while (prev < n && deleted[prev]) {
                prev++;
            }
            rep_(i, prev + 1, n) {
                if (!deleted[i]) {
                    if (v[prev] > v[i]) {
                        flag = false;
                        break;
                    } else {
                        prev = i;
                    }
                }
            }
            ans++;
            if (flag) {
                break;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}