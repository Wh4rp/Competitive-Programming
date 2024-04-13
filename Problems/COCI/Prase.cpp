#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> contador;
    
    int n, sol = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int c = 0;  // cantidad que han comido los demas
                    // sin contar al s
        
        for(auto x : contador){
            // x.first la llave
            // x.second el valor asociado a la llave
            c += x.second; // c = c + x.second;
        }
        c -= contador[s];

        // aca c tiene el valor actualizado

        if(c < contador[s]){
            sol++;
        }

        contador[s]++; // s ha comido un trozo
    }

    cout << sol << '\n';

    return 0;
}