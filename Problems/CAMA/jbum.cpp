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

    int N;
    cin >> N;
    vector<int> v;
    while (N > 1) {
        v.push_back(N / 2);
        if (N % 2 == 0) {
            N = N / 2;
        } else {
            N = N / 2 + 1;
        }
    }

    reverse(v.begin(), v.end());
    cout << v.size() << '\n';
    for (auto x : v)
        cout << x << ' ';
    cout << '\n';

    return 0;
}