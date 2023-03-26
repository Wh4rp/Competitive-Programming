#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

// Max sum of a subarray
ll kadane(vector<ll>& a) {
    ll max_so_far = a[0];
    ll curr_max = a[0];
    for (int i = 1; i < a.size(); i++) {
        curr_max = max(a[i], curr_max + a[i]);
        max_so_far = max(max_so_far, curr_max);
    }
    return max_so_far;
}

// Min sum of a subarray
ll kadane_min(vector<ll>& a) {
    ll min_so_far = a[0];
    ll curr_min = a[0];
    for (int i = 1; i < a.size(); i++) {
        curr_min = min(a[i], curr_min + a[i]);
        min_so_far = min(min_so_far, curr_min);
    }
    return min_so_far;
}

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

        vector<ll> a(n);
        rep(i, n) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<ll> b(n);
        int i = 1, j = n - 1;
        ll acumlate_sum = b[0] = a[0];
        bool sum_is_negative = true;

        for (int k = 1; k < n; k++) {
            if (!sum_is_negative) {
                b[k] = a[i];
                acumlate_sum += a[i];
                i++;
            } else {
                b[k] = a[j];
                acumlate_sum += a[j];
                j--;
            }
            sum_is_negative = acumlate_sum < 0;
        }
        int rango = abs(a[0] - a[n - 1]);
        if (kadane(b) < rango && abs(kadane_min(b)) < rango) {
            cout << "YES" << '\n';
            rep(i, n) {
                cout << b[i] << " ";
            }
            cout << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}