#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main() {
    // ofstream out("peru.text");
    long long n, b;

    while (cin >> n >> b && n != -1 && b != -1) {
        multiset<pair<long long, pair<long long, long long>>> ciudades;
        long long p;
        b -= n;
        for (long long i = 0; i < n; i++) {
            cin >> p;
            ciudades.insert({p, {1, p}});
        }

        while (b > 0) {
            auto rit = ciudades.rbegin();

            pair<long long, pair<long long, long long>> lastElement = *rit;
            ciudades.erase(*rit);
            lastElement.second.first++;
            lastElement.first =
                lastElement.second.second / lastElement.second.first;
            if (lastElement.second.second % lastElement.second.first != 0) {
                lastElement.first++;
            }

            ciudades.insert(lastElement);
            // actualizamos la ultima posicion de memoria del set haciendole ++;
            // al .second y luego .first=/.second
            b--;
        }
        pair<long long, pair<long long, long long>> lastElement =
            *ciudades.rbegin();

        cout << lastElement.first << endl;
        // hacemos out de la ultima posicion de memoria.first
    }

    return 0;
}