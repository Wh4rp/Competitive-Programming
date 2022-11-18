#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

struct Number {
    int mod, sum;
    string num;
    Number(int mod, int sum, string num) : mod(mod), sum(sum), num(num) {}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    bool visited[505][5005];
    memset(visited, false, sizeof(visited));

    int d, s;
    cin >> d >> s;

    queue<Number> q;

    q.push(Number(0, 0, ""));
    visited[0][0] = true;

    while (!q.empty()) {
        Number n = q.front();
        q.pop();

        if (n.sum == s && n.mod == 0) {
            cout << n.num << '\n';
            return 0;
        }

        rep_(i, 0, 10) {
            int new_mod = (n.mod * 10 + i) % d;
            int new_sum = n.sum + i;
            if (new_sum <= s && !visited[new_mod][new_sum]) {
                q.push(Number(new_mod, new_sum, n.num + to_string(i)));
                visited[new_mod][new_sum] = true;
            }
        }
    }

    cout << -1 << '\n';

    return 0;
}