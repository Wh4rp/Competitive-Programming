#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int caso = 1; caso <= t; caso++){
        cout << "Case " << caso << ": ";
        string s, r;
        cin >> s >> r;
        int count_01 = 0;
        int count_10 = 0;
        int count_x0 = 0;
        int count_x1 = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '0' && r[i] == '1'){
                count_01++;
            }
            if(s[i] == '1' && r[i] == '0'){
                count_10++;
            }
            if(s[i] == '?' && r[i] == '0'){
                count_x0++;
            }
            if(s[i] == '?' && r[i] == '1'){
                count_x1++;
            }
        }
        int count = min(count_01, count_10);
        count_01 -= count;
        count_10 -= count;
        if(count_10 == 0) {
            count += count_01 + count_x0 + count_x1;
        }
        else {
            int count1 = min(count_10, count_x1);
            count_x0 += count1;
            count_x1 -= count1;
            count_10 -= count1;
            count += count1;
            if (count_10){
                count = -1;
            }
            else {
                count += count_x0 + count_x1;
            }
        }
        cout << count << '\n';
    }
}