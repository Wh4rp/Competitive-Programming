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

    int a, b, two = 0, three = 0, five = 0;
    cin >> a >> b;
    while (a % 2 == 0) {
        a /= 2;
        two++;
    }
    while (a % 3 == 0) {
        a /= 3;
        three++;
    }
    while (a % 5 == 0) {
        a /= 5;
        five++;
    }
    while (b % 2 == 0) {
        b /= 2;
        two--;
    }
    while (b % 3 == 0) {
        b /= 3;
        three--;
    }
    while (b % 5 == 0) {
        b /= 5;
        five--;
    }
    if (a != b) {
        cout << -1 << '\n';
    } else {
        cout << abs(two) + abs(three) + abs(five) << '\n';
    }

    return 0;
}