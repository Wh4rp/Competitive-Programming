#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int n, m;
    cin >> n >> m;
    vector<int> atack, defense;
    rep(i, n){
        string position;
        int strength;
        cin >> position >> strength;
        if(position == "ATK") atack.push_back(strength);
        else defense.push_back(strength);
    }
    vector<int> jiro_cards;
    rep(i, m){
        int strength;
        cin >> strength;
        jiro_cards.push_back(strength);
    }

    sort(atack.begin(), atack.end());
    sort(defense.begin(), defense.end());
    sort(jiro_cards.begin(), jiro_cards.end());
    int strategy1 = 0, strategy2 = 0;

    // no kill defense cards
    int l = 0, r = jiro_cards.size() - 1;
    while(l < atack.size() && r >= 0){
        if(atack[l] <= jiro_cards[r]){
            strategy1 += jiro_cards[r] - atack[l];
            l++;
            r--;
        }
        else break;
    }
    if(l == atack.size() && n == atack.size()){
        while(r >= 0){
            strategy1 += jiro_cards[r];
            r--;
        }
    }

    // kill defense cards
    l = 0, r = 0;
    while(l < defense.size() && r < jiro_cards.size()){
        if(defense[l] < jiro_cards[r]){
            jiro_cards[r] = -1;
            l++;
            r++;
        }
        else r++;
    }
    if(l == defense.size()){
        l = 0;
        r = 0;
        while(l < atack.size() && r < jiro_cards.size()){
            if(atack[l] <  jiro_cards[r]){
                strategy2 += jiro_cards[r] - atack[l];
                jiro_cards[r] = -1;
                l++;
                r++;
            }
            else r++;
        }
        if(l == atack.size()){
            rep(i, jiro_cards.size()){
                if(jiro_cards[i] != -1) strategy2 += jiro_cards[i];
            }
        }
    }

    cout << max(strategy1, strategy2) << '\n';

    return 0;
}