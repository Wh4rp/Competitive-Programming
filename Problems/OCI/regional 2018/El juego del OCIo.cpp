#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> vect;

    int largo = 0;
    vect.push_back("1");
    largo++;

    if (N != 1) {
        for (int i = 0; i < N - 1; i++) {
            string ultimo_sec = vect[largo - 1];
            cout << ultimo_sec << '\';
            string agregar = "";
            int cont = 1;
            for (int j = 0; j < ultimo_sec.size(); j++) {
                if(j == ultimo_sec.size() - 1){
                    agregar =
                        agregar + to_string(cont) + to_string(ultimo_sec[j]);
                    cont = 1;
                }
                else if (ultimo_sec[j] == ultimo_sec[j + 1]) {
                    // el caracter j-esimo es igual al
                    // caracter (j+1)-esimo, o sea al
                    // siguiente
                    cont++;
                } else {
                    // guardamos ultimo_sec[j]
                    // ya que esta repetido
                    // cont veces
                    agregar =
                        agregar + to_string(cont) + to_string(ultimo_sec[j]);
                    cont = 1;
                }
            }
            vect.push_back(agregar);
            largo++;
        }
    }

    for(auto x : vect){
        cout << x << '\n';
    }

    return 0;
}