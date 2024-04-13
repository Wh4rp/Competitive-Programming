#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

function binsearch(array, i, j) {
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

ll v[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        rep(i, n) cin >> v[i];
    }

    return 0;
}