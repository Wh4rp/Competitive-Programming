#include <bits/stdc++.h>
using namespace std;

int bitRemoval(int x, int y) {
    return x ^ (x & y);
}
   
int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int x, y;
        cin >> x >> y;
        cout << bitRemoval(x, y) << "\n";
    }
    return 0;
}
