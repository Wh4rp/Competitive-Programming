#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;
 
// set of pairs (value, id)
typedef tree<
    pair<int, int>,
    null_type,
    less<pair<int, int>>, // Comparación basada en el primer elemento del par
    rb_tree_tag,
    tree_order_statistics_node_update>
ordered_set;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);
 
    ordered_set s;
    
    int n, acc = 0;
    int c[n];
    ll ans = 0;
    cin >> n;
    
    // Almacenar los pares en el conjunto
    rep(i, n) {
        cin >> c[i];
        if(c[i] == 1) ans++;
        acc += c[i];
        s.insert({acc, i});
    }
    
    acc = 0;
 
    rep(i, n) {
        int min_val = acc + 1;
        acc += c[i];
 
        // Borrar el elemento correspondiente
        s.erase({acc, i});
 
        // Encontrar el elemento que es mayor o igual a min_val
        auto it = s.lower_bound({min_val, 0}); // Solo importa el primer valor
        if (it != s.end()) {
            ll order = s.order_of_key(*it);
            ans += s.size() - order;
        }
    }
 
    cout << ans << '\n';
 
    return 0;
}