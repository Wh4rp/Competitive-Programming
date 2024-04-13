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

    vector<int> conut_div(1000001, 0);

    rep(i, 1000001){
        for(int j = i; j < 1000001; j += i)
            conut_div[j]++;
    }

    int n;
    cin >> n;
    rep(i, n){
        int x;
        cin >> x;
        cout << conut_div[x] << '\n';
    }

    return 0;
}