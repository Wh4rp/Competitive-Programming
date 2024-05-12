#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

char seq[400];
int len_seq;

void fill_seq(){
    int i = 0;
    rep_(j, 1, 26){
        seq[i] = 'Z';
        i++;
        rep(k, j){
            seq[i] = 'Z' - (j - k);
            i++;
        }
    }
    seq[i] = 'Z';
    len_seq = i + 1;
}

int dis[10005];
char tree_land[10005];
int node_start = 0, node_end = -1;

void dfs(int node, vector<vector<int>> &graph, int d){
    dis[node] = d;
    if(node_end == -1 && dis[node] > dis[node_start]){
        node_start = node;
    }
    else if(node_end != -1 && dis[node] > dis[node_end]){
        node_end = node;
    }
    for(auto x : graph[node]){
        if(dis[x] == -1){
            dfs(x, graph, d + 1);
        }
    }
}

void find_diameter(int node, vector<vector<int>> &graph){
    memset(dis, -1, sizeof(dis));
    dfs(node, graph, 0);
    node_end = node_start;
    memset(dis, -1, sizeof(dis));
    dfs(node_start, graph, 0);
}

void fill_tree(int node, int seq_i, vector<vector<int>> &graph){
    // cout << node << ' ' << seq_i << '\n';
    tree_land[node] = seq[seq_i];
    // cout << tree_land[node] << '\n';
    for(auto x : graph[node]){
        if(tree_land[x] == '-'){
            fill_tree(x, seq_i + 1, graph);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    rep(i, n-1){
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    fill_seq();
    // rep(i, len_seq){
    //     cout << seq[i];
    // }
    // cout << '\n';

    memset(dis, -1, sizeof(dis));

    find_diameter(0, graph);

    if (dis[node_end] + 1 > 351) {
        cout << "Impossible!\n";
        return 0;
    }
    
    memset(tree_land, '-', sizeof(tree_land));

    // rep(i, 351){
    //     cout << seq[i];
    // }
    // cout << '\n';

    // rep(i, n){
    //     cout << tree_land[i] << ' ';
    // }
    // cout << '\n';

    cout << "Node start: " << node_start + 1 << '\n';
    cout << "Node end: " << node_end + 1 << '\n';
    
    fill_tree(node_start, 0, graph);

    rep(i, n){
        cout << tree_land[i] << ' ';
    }
    cout << '\n';

    return 0;
}