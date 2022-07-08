#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

ll n, l, k, d[505], a[505], next_coord[505], back_coord[505];
bool visited[505];

ll road_time(int i, int j){
  return d[i] * (a[j] - a[i]);
}

// Custom compaarator for priority queue
struct comp{
  bool operator()(const pair<int, int>& a, const pair<int, int>& b){
    return road_time(a.first, a.second) > road_time(b.first, b.second);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  
  cin >> n >> l >> k;
  rep(i, n) cin >> d[i];
  rep(i, n) cin >> a[i];
  a[n] = l;
  rep(i, n){
    next_coord[i] = i + 1;
    back_coord[i] = i - 1;
    visited[i] = false;
  }

  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, comp> pq;
  
  rep_(i, 1, n - 1){
    pq.push({i, i+1});
  }

  while(k>0){
    auto p = pq.top();
    pq.pop();
    int i = p.first, j = p.second;
    while(j != next_coord[i]){
      p = pq.top();
      pq.pop();
      i = p.first, j = p.second;
    }
    k--;
    visited[i] = true;

    cout << i << ' ' << j << '\n';

    if(back_coord[i] != 0){
      pq.push({back_coord[i],next_coord[i]});
    }
    back_coord[j] = back_coord[i];
    next_coord[back_coord[i]] = j;
  }
  int i = 0;
  ll ans = 0;
  rep(j, n){
    if(!visited[i]){
      ans += road_time(i, j);
      i = j;
    }
  }
  ans += road_time(i, n);

  cout << ans << '\n';

  return 0;
}