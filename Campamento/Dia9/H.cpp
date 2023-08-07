#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
struct SuffixAutomaton {
    struct state {
        // link es el estado al que debe volver para seguir estando en el
        // substring mÃ¡s largo. link serian los arcos morados.

        // len es el largo del sufijo mas largo del que el nodo se encarga.
        // (camino mas largo)
        int len, link;

        // next['c'] indica la posicion del nodo al que va un estado
        // al recorrer la arista que corresponde a la letra 'c'.
        // cuidado que si no esta la arista de letra 'c' entonces
        // dara 0.
        map<char, int> next;
    };
    // estados (nodos)
    int MAXLEN;
    vector<state> st;
    // lista de estados
    int sz, last;
    // sz es el numero de estados
    SuffixAutomaton(int n = 1e5) : MAXLEN(n) {
        st.resize(n << 1);
        last = st[0].len = 0;
        st[0].link = -1;
        sz = 1;
    }

    // Agregar un caracter al final del string.
    void add(char c) {
        int cur = sz++;
        st[cur].len = st[last].len + 1;
        int p = last;
        while (p != -1 && !st[p].next.count(c)) {
            st[p].next[c] = cur;
            p = st[p].link;
        }
        if (p == -1)
            st[cur].link = 0;
        else {
            int q = st[p].next[c];
            if (st[p].len + 1 == st[q].len)
                st[cur].link = q;
            else {
                int clone = sz++;
                st[clone].len = st[p].len + 1;
                st[clone].next = st[q].next;
                st[clone].link = st[q].link;
                while (p != -1 && st[p].next[c] == q) {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string S;
    cin >> S;

    // Inicio el suffix automaton.
    SuffixAutomaton SA(S.size() + 1);

    // Le coloco todos los caracteres del string.
    for (char c : S)
        SA.add(c);
    int cant = 0;
    for (int i = 0; i < SA.sz; i++) {
        cant++;
        // el nodo i-esimo se encarga de substrings unicos de largo
        // [SA.st[SA.st[i].link].len + 1, SA.st[i].len]
        // El largo del link mas 1, y el largo del nodo i.
        if (SA.st[i].len >= k and SA.st[SA.st[i].link].len + 1 <= k) {
            cant++;
        }
    }
    cout << cant << '\n';

    return 0;
}