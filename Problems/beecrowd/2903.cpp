#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    double R;
    cin >> R;
    R *= 100;
    int r = int(R);
    cout << 36000 / __gcd(36000, r) << '\n';

    return 0;
}