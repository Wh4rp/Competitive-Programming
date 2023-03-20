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

    int n, m;

    cin >> n >> m;

    int nums[2000] = {0};

    rep(i, n) {
        int a;
        cin >> a;
        nums[a%1000]++;
    }
    int count = 0;
    rep(i, m) {
        int a;
        cin >> a;
        if(nums[a%1000] != 0){
            count += nums[a%1000];
            nums[a%1000] = 0;
        }
    }

    cout << count << '\n';

    return 0;
}