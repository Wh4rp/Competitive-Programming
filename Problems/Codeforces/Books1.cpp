#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define loop(i, a, b) for (long long i = a; i < b; i++)
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define ff first
#define ss second
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define write(x) cout << x << "\n"

long int book[100100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    // #ifndef Mishra
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    long int i, j, n, time, ans, sum;
    cin >> n >> time;
    for (i = 0; i < n; i++) {
        cin >> book[i];
    }
    // sort(book,book+n);
    // b1 b2 b3 b4 b5 b6
    //    j        i

    j = -1, sum = 0, ans = 0;
    for (i = 0; i < n; i++) {
        if (sum + book[i] <= time)
            sum += book[i];
        else {
            sum += book[i];
            while (sum > time) {
                j++;
                sum -= book[j];
            }
        }
        ans = max(ans, i - j);
    }
    cout << ans << endl;

    return 0;
}