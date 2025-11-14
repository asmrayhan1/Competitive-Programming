#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
long long n, m, timer, mn = 1e18; // number of nodes
int const N = 2e5 + 10;

vector<pair<int, int>> edges;
vector<int> vis, tin, low, adj[N];

void dfs(int v, int p = -1){
    vis[v] = true;
    tin[v] = low[v] = timer++;
    bool parent_skipped = false;
    for (int to : adj[v]) {
        if (to == p && !parent_skipped) {
            parent_skipped = true;
            continue;
        }
        if (vis[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                edges.push_back({v, to});
        }
    }
}

void find_bridges(){
    timer = 0;
    vis.assign(n + 1, false);
    tin.assign(n + 1, -1);
    low.assign(n + 1, -1);
    for (int i = 1; i <= n; i++){
        if (!vis[i])
            dfs(i);
    }
}

int main(){
  
}
