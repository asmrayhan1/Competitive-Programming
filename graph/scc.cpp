#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
int n, num_of_comp = 0;
const int MX = 50010;
vector<int> vis(MX), g[MX], gr[MX], comp[MX];
stack<int> st;
 
void dfs(int u){
    vis[u] = 1;
    for (auto v : g[u]){
        if (!vis[v]){
            dfs(v);
        }
    }
    st.push(u);
}
 
void dfs2(int u){
    vis[u] = 1;
    comp[num_of_comp].push_back(u);
    for (auto v : gr[u]){
        if (!vis[v]){
            dfs2(v);
        }
    }
}
 
int main(){
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++){
        cin >> n;
        for (int i = 1; i <= n; i++){
            vis[i] = 0;
            g[i].clear();
            gr[i].clear();
            comp[i].clear();
        }
        num_of_comp = 0;
        for (int i = 1; i <= n; i++){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            gr[v].push_back(u);
        }
        for (int i = 1; i <= n; i++){
            if (!vis[i]){
                dfs(i);
            }
        }
        for (int i = 1; i <= n; i++) vis[i] = 0;
        while (!st.empty()){
            int x = st.top();
            st.pop();
            if (!vis[x]){
                num_of_comp++;
                dfs2(x);
            }
        }
        int mx = 0, node = 0;
        for (int i = 1; i <= num_of_comp; i++){
            sort(comp[i].begin(), comp[i].end());
            if (comp[i].size() > mx){
                mx = comp[i].size();
                node = comp[i][0];
            } else if (comp[i].size() == mx){
                node = min(node, comp[i][0]);
            }
        }
        cout << "Case " << tt << ": " << node << endl;
    }
}
