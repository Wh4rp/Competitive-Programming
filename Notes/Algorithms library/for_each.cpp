#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

int main() {

    vector<int> v = {1, 2, 3, 4, 5};
    int v2[] = {1, 2, 3, 4, 5};

    auto print = [](const int& n) { cout << " " << n; };

    cout << "Using in vector:";

    for_each(v.begin(), v.end(), print);

    cout << '\n';

    cout << "Using in array:";

    for_each(v2, v2 + 5, print);

    cout << '\n';

    for_each(v2, v2 + 5, [](int &n){ n++; });

    for_each(v2, v2 + 5, print);

    return 0;
}