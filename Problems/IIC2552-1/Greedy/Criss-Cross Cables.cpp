#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

int sockets[500005], cables[500005];

ll dis_sockets(int i, int j){
  return abs(sockets[j] - sockets[i]);
}

struct ComparatorLength
 {
  bool operator()(const pair<ll, ll>& a, const pair<ll, ll>& b) const {
    return dis_sockets(a.second, a.first) > dis_sockets(b.second, b.first);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  
  int n, m;
  cin >> n >> m;
  rep(i, n) cin >> sockets[i];
  rep(i, m) cin >> cables[i];
  sort(cables, cables + m);

  priority_queue<pair<ll, ll>, vector<pair<ll,ll>>, ComparatorLength> pq;
  rep(i, n - 1){
    pq.push(make_pair(i, i+1));
  }

  int i = 0;
  while(i < m && !pq.empty()){
    if(dis_sockets(pq.top().second, pq.top().first) > cables[i]){
      break;
    }
    else{
      if(pq.top().second < n - 1){
        pq.push(make_pair(pq.top().first, pq.top().second + 1));
      }
      pq.pop();
      i++;
    }
  }

  if(i < m){
    cout << "no\n";
  }
  else{
    cout << "yes\n";
  }

  return 0;
}