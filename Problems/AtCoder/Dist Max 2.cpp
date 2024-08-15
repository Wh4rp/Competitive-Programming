#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

ll distance_points(pair<int, int> a, pair<int, int> b){
    return min(abs(a.first - b.first), abs(a.second - b.second));
}

vector<pair<int, int>> points;

ll binsearch(array, i, j) {
    // assert(i < j) // since the range is [i,j), then j must be > i
    while (i < j) {
        m = (i+j) / 2;
        if (predicate(array[m]))
            j = m
        else
            i = m + 1
    }
    return i; // notice that i == j if the predicate is false for the whole range
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int n;
    cin >> n;

    rep(i, n){
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }

    sort(points.begin(), points.end());
    

    return 0;
}