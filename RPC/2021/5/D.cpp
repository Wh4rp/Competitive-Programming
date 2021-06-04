#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define REPGET(_1, _2, _3, NAME, ...) NAME
#define rep3(i, b, n) for (int i = b; i < n; i++)
#define rep2(i, n) rep3(i, 0, n)
#define rep(...) REPGET(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define invrep3(i, b, n) for (int i = n - 1; i >= b; i--)
#define invrep2(i, n) invrep3(i, 0, n)
#define invrep(...) REPGET(__VA_ARGS__, invrep3, invrep2)(__VA_ARGS__)

struct Dam {
  vector<int> up;
  int parent;
  int cap;
  int cur;
};

int n;
Dam dams[200001];

int optimal_rain_for(int at, int needed) {
  Dam& dam = dams[at];
  int needed_here = max(needed, dam.cap) - dam.cur;
  int minrain = needed_here;
  for (const int& child_idx : dam.up) {
    minrain = min(minrain, optimal_rain_for(child_idx, needed_here));
  }
  return minrain;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int campw;
  cin >> n >> campw;
  dams[0] = {{}, 0, campw, 0};
  rep(i, 1, n + 1) {
    int parent, cap, cur;
    cin >> parent >> cap >> cur;
    dams[i] = {{}, parent, cap, cur};
  }
  rep(i, 1, n + 1) { dams[dams[i].parent].up.push_back(i); }
  cout << optimal_rain_for(0, campw) << endl;
}
