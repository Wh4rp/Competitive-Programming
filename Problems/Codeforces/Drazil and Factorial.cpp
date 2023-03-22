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

    int factors[] = {0, 0, 0, 0};
    //   2  3  5  7
    int n;
    string s;

    cin >> n >> s;

    rep(i, n) {
        switch (s[i]) {
            case '2':
                factors[0] += 1;
                break;
            case '3':
                factors[0] += 1;
                factors[1] += 1;
                break;
            case '4':
                factors[0] += 3;
                factors[1] += 1;
                break;
            case '5':
                factors[0] += 3;
                factors[1] += 1;
                factors[2] += 1;
                break;
            case '6':
                factors[0] += 4;
                factors[1] += 2;
                factors[2] += 1;
                break;
            case '7':
                factors[0] += 4;
                factors[1] += 2;
                factors[2] += 1;
                factors[3] += 1;
                break;
            case '8':
                factors[0] += 7;
                factors[1] += 2;
                factors[2] += 1;
                factors[3] += 1;
                break;
            case '9':
                factors[0] += 7;
                factors[1] += 4;
                factors[2] += 1;
                factors[3] += 1;
                break;
            default:
                break;
        }
    }

    vector<char> ans;

    while (factors[3]) {
        ans.push_back('7');
        factors[0] -= 4;
        factors[1] -= 2;
        factors[2] -= 1;
        factors[3] -= 1;
    }

    while (factors[2]) {
        ans.push_back('5');
        factors[0] -= 3;
        factors[1] -= 1;
        factors[2] -= 1;
    }

    while (factors[1]) {
        ans.push_back('3');
        factors[0] -= 1;
        factors[1] -= 1;
    }

    while (factors[0]) {
        ans.push_back('2');
        factors[0] -= 1;
    }

    for (char x : ans) {
        cout << x;
    }

    cout << '\n';

    return 0;
}