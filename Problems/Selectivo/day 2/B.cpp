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
  
  int n;
  cin >> n;
  vector<string> names(n), surnames(n);
  map<string, int> repited;
  rep(i, n){
    cin >> names[i] >> surnames[i];
    if(repited.count(names[i])){
      repited[names[i]]++;
    }else{
      repited[names[i]] = 1;
    }
    if(repited.count(surnames[i])){
      repited[surnames[i]]++;
    }else{
      repited[surnames[i]] = 1;
    }
    if(names[i] == surnames[i]){
      repited[names[i]]--;
    }
  }
  rep(i, n){
    if(repited[names[i]] >= 2 && repited[surnames[i]] >= 2){
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  
  return 0;
}