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

struct Tap {
  int t;
  int min;
  int max;
};

struct Recipe {
  int t;
  int flow;
};

int k;
Tap taps[10];

int conf[10];

bool tap_lt_temp(const Tap& a, const Tap& b) {
  return a.t < b.t;
}

void printconf() {
  /*double flow = 0.;
  double heat = 0.;
  rep(i, k) {
      flow += conf[i];
      heat += conf[i] * taps[i].t;
      cout << conf[i] << " ";
  }
  cout << "| flow = " << flow << ", temp = " << (heat / flow) << endl;*/
}

// 0:  10°C (0 - 10) -> 10 => 10*10 = 100
// 1:  0°C (0 - 1000) -> 10 => 0

bool check(int ttemp, int tflow) {
  int minflow = 0;
  int maxflow = 0;
  int baseheat = 0;
  rep(i, k) {
    conf[i] = taps[i].min;
    minflow += taps[i].min;
    maxflow += taps[i].max;
    baseheat += taps[i].min * taps[i].t;
  }
  if (minflow > tflow) {
    // cout << "too much forced flow" << endl;
    return false;
  } else if (maxflow < tflow) {
    return false;
  }

  int flow = minflow;
  int minheat = baseheat;
  rep(i, k) {
    if (flow >= tflow) {
      break;
    }
    int addflow = min(taps[i].max - taps[i].min, tflow - flow);
    flow += addflow;
    minheat += addflow * taps[i].t;
  }
  assert(flow == tflow);

  flow = minflow;
  int maxheat = baseheat;
  invrep(i, k) {
    if (flow >= tflow) {
      break;
    }
    int addflow = min(taps[i].max - conf[i], tflow - flow);
    flow += addflow;
    minheat += addflow * taps[i].t;
  }
  if (minheat > ttemp * tflow) {
    return false;
  } else if (maxheat < ttemp * tflow) {
    return false;
  }

  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> k;
  rep(i, k) { cin >> taps[i].t >> taps[i].min >> taps[i].max; }
  sort(&taps[0], &taps[k], tap_lt_temp);

  int rs;
  cin >> rs;
  rep(r, rs) {
    int ttemp, tflow;
    cin >> ttemp >> tflow;
    if (check(ttemp, tflow)) {
      cout << "yes\n";
    } else {
      cout << "no\n";
    }
    // cout << endl;
  }
}
