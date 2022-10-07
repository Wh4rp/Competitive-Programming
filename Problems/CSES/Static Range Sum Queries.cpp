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

    int n, q;
    cin >> n >> q;

    ll nums[n], partial_sum[n+1];
    rep(i, n) cin >> nums[i];
    partial_sum[0] = 0;
    rep_(i, 1, n+1) partial_sum[i] = partial_sum[i - 1] + nums[i-1];
    rep(i, q){
        int a, b;
        cin >> a >> b;
        cout << partial_sum[b] - partial_sum[a-1] << '\n';
    }

    return 0;
}