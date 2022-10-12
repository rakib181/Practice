#include<bits/stdc++.h>
using namespace std;
const int N = 26;
vector<int> g[N];
vector<bool> vis(N, false);

void dfs(int cur, int par){
    if(cur != par)cout << (char) (cur + 'A') << ' ';
    vis[cur] = true;
    for(auto x : g[cur]){
        if(!vis[x]){
            dfs(x, par);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        char u, v;
        cin >> u >> v;
        g[u - 'A'].push_back(v - 'A');
    }
    char start;
    cin >> start;
    dfs(start - 'A', start - 'A');
    return 0;
}
