#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

int count_subordinates(int employee,
                       vector<vector<int>>& subordinates,
                       vector<int>& num_subordinates) {
    if (subordinates[employee].size() == 0) {
        num_subordinates[employee] = 0;
        // cout << "employee: " << employee << " has " << 0 << '\n';
        return 1;
    } else {
        int num = 0;
        for (int x : subordinates[employee]) {
            num += count_subordinates(x, subordinates, num_subordinates);
        }
        num_subordinates[employee] = num;
        // cout << "employee: " << employee << " has " << num << '\n';
        return num + 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int n;
    cin >> n;

    vector<vector<int>> subordinates(n);

    rep(i, n - 1) {
        int boss;
        cin >> boss;
        boss--;
        subordinates[boss].push_back(i + 1);
    }

    // print subordinates

    // for(auto x : subordinates) {
    //     cout << x.size() << ' ';
    // }

    // cout << '\n';

    vector<int> num_subordinates(n);

    count_subordinates(0, subordinates, num_subordinates);

    for (int num : num_subordinates) {
        cout << num << ' ';
    }

    cout << '\n';

    return 0;
}