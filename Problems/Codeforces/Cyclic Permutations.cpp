#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long ans1 = 1, ans2 = 1;

    for (int i = 1; i <= n; i++) {
        ans1 *= i;
        ans1 = ans1 % 1000000007;
        if (i != 1) {
            ans2 *= 2;
            ans2 = ans2 % 1000000007;
        }
    }

    cout << (1000000007 + ans1 - ans2) % 1000000007 << '\n';
}