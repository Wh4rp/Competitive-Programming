#include <bits/stdc++.h>
using namespace std;

int main() {

    int dias, participantes;
    map<int, int> ultima_participacion;

    cin >> dias;

    for(int i = 1; i <= dias; i++){
        cin >> participantes;
        for(int j = 0; j < participantes; j++){
            int participante;
            cin >> participante;
            ultima_participacion[participante] = i;
        }
    }

    map<int, int> ganador;

    for(auto x : ultima_participacion){
        // x.first := id del participante
        // x.second := el dia de la ultima participacion de x.first
        if(ganador[x.second] == 0){
            ganador[x.second] = x.first;
        }
    }

    bool posible = true;

    for(int i = 1; i <= dias; i++){
        if(ganador[i] == 0){
            posible = false;
            break;
        }
    }

    if(posible == false){
        cout << "-1\n";
    }
    else{
        for(auto x : ganador){
            // x.first := el dia
            // x.second := el ganador del dia x.first
            cout << x.second << ' ';
        }
        cout << '\n';
    }

    return 0;
}