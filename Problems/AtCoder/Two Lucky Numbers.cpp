#include <bits/stdc++.h>

using namespace std;

int main() {
    string A, B;
    cin >> A >> B;
    cout << A << '0';

    B += '0';
    bool Acumulado = false;
    for (char i : B) {
        if (!Acumulado) {
            int u = i - '0';
            cout << u / 2;
            if (u % 2 == 1) {
                Acumulado = true;
            }
        } else {
            int u = i - '0';
            cout << 5 + (u / 2);
            if (u % 2 == 0) {
                Acumulado = false;
            }
        }
    }
    return 0;
};