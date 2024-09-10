#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

int num_testcases;
int N;
int next_appear[200000];
vector<int> balls;
vector<int> DP;

// Returns balls that can be killed to the right
int dp(int index, bool iscounted) {
    if (index >= N)
        return 0;
    if (index == N - 1)
        return iscounted;
    if (DP[index] != -1)
        return DP[index];

    // 2 choices
    int skip = dp(index + 1, false) + iscounted;

    int curr_colour = balls[index];

    int next = next_appear[index];

    int delete_count = 0;
    if (next != -1) {
        delete_count = (next - index) + dp(next, true);
    }

    int ans = max(skip, delete_count);

    DP[index] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int t;
    cin >> t;

    while (t--) {
        cin >> N;
        balls.resize(N);
        DP.assign(N, -1);

        vector<int> appears_of_numbers[N + 1];

        for (int i = 0; i < N; ++i) {
            cin >> balls[i];
            appears_of_numbers[balls[i]].push_back(i);
            int k = appears_of_numbers[balls[i]].size();
            if (k > 1){
                next[]
            }
        }

        rep(i, N + 1) next_appear[i] = -1;

        rep(i, N) {
            cout << "Las apariciones del " << i << " son "
                 << appears_of_numbers[i].size() << '\n';
            // for (int j = 0; j < appears_of_numbers[i].size() - 1; j++) {
            //     int prev = appears_of_numbers[i][j];
            //     int next = appears_of_numbers[i][j + 1];
            //     next_appear[prev] = next;
            // }
        }

        rep(i, N) cout << next_appear[i] << ' ';

        cout << '\n';

        // int ans = dp(0, false);
        // rep(i, N) cout << "DP de " << i << ": " << DP[i] << '\n';
        // cout << ans << '\n';
    }

    return 0;
}
