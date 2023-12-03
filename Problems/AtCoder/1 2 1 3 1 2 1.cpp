#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

vector<string> dp(10000, "");

string fun(int n){
    if(dp[n] != "")
        return dp[n];
    if(n == 1)
        return "1";
    else
        return dp[n] = fun(n-1) + " " + to_string(n) + " " + fun(n-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int n;
    cin >> n;
    cout << fun(n) << '\n';

    return 0;
}