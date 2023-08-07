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
        int n;
        cin >> n;
        int graph[n + 1][n + 1];
        for (int i = 1; i <= n / 2; i++) {
            int init = 0, cont = 0, curr = 0;
            while (cont != n) {
                int next = (curr + i) % n;
                graph[curr][next] = 1 * (2 * i != n);
                graph[next][curr] = -1 * (2 * i != n);
                curr = next;
                cont++;
                if (curr == init) {
                    init++;
                    curr = init;
                }
            }
        }
        rep(i, n - 1) {
            rep_(j, i + 1, n) {
                cout << graph[i][j] << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}