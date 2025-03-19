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

    int a, b, c, d, e;

    cin >> a >> b >> c >> d >> e;

    set<pair<int, string>> participants;

    rep_(i, 1, 32) {
        int score = 0;
        string name = "";
        if(i & (1)) {
            score += a;
            name += "A";
        }
        if(i & (2)) {
            score += b;
            name += "B";
        }
        if(i & (4)) {
            score += c;
            name += "C";
        }
        if(i & (8)) {
            score += d;
            name += "D";
        }
        if(i & (16)) {
            score += e;
            name += "E";
        }

        participants.insert({-score, name});
    }

    for(auto [score, name] : participants){
        cout << name << '\n';
    }

    return 0;
}