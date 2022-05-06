#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

class Event {
  public:
    int time, type, high;
};

struct CompareEvent {
    bool operator()(Event const& e1, Event const& e2)
    {
        return e1.time > e2.time;
    }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  
  priority_queue<Event, vector<Event>, CompareEvent> Q;
  multiset<int, greater<int>> Highs;
  Highs.insert(0);
  vector<int> sol;
  int left, right, high, cont = 0;

  while(cin >> left >> high >> right){
  	Q.push({left, 0, high});
  	Q.push({right, 1, high});
  }
  int top = 0;
  while (!Q.empty()){
  	Event temp;

  	do{
  		temp = Q.top();
		Q.pop();

	  	if(temp.type == 0){
	  		Highs.insert(temp.high);
	  	}
	  	else{
	  		Highs.erase(Highs.find(temp.high));
	  	}
  	}while(!Q.empty() && Q.top().time == temp.time);
  	if(top != *Highs.begin()){
  		top = *Highs.begin();
  		sol.push_back(temp.time);
  		sol.push_back(top);
  		cont++;
  	}
  }
  for (int i = 0; i < cont; ++i)
  {
  	cout << sol[2*i] << ' ' << sol[2*i + 1] << " \n"[i == cont - 1];
  }
  return 0;
}