#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

struct Event {
    int x, h, type;
    Event(int x, int h, int type) : x(x), h(h), type(type) {}
    bool operator<(const Event& e) const { return x < e.x; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int x1, x2, h;
    vector<Event> events;

    while (cin >> x1 >> h >> x2) {
        events.push_back(Event(x1, h, 1));
        events.push_back(Event(x2, h, -1));
    }

    sort(events.begin(), events.end());

    multiset<int> heights;
    heights.insert(0);

    int i = 0, n = events.size();

    while (i < n) {
        do {
            if (events[i].type == 1)
                heights.insert(events[i].h);
            else
                heights.erase(heights.find(events[i].h));
        } while (i < n - 1 && events[i].x == events[i + 1].x && ++i);

        cout << events[i].x << ' ' << *heights.rbegin() << " \n"[i == n - 1];
        i++;
    }

    return 0;
}