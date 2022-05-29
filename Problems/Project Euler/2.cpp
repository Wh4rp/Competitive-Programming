#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {  
  ll sum = 2;

  ll f, f1 = 1, f2 = 2;
  while(1){
  	f = f1 + f2;
  	if(f > 4000000)
  		break;
  	if(f % 2 == 0)
      sum += f;
    f1 = f2;
    f2 = f;
  }
  cout << sum << '\n';
  return 0;
}