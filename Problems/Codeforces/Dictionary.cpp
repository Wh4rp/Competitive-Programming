#include<bits/stdc++.h>

using namespace std;

int main(){
  
  int t;
  cin >> t;

  while(t--){
    string s; 
    cin >> s;
    cout << 25 * (int(s[0]) - 97) + int(s[1]) - 96 - (s[0] < s[1])<< '\n';
  }

  return 0;
}
