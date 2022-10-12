#include <bits/stdc++.h>
using namespace std;

class mst{
public:
    vector<pair<int, int>> *l;
    int N;
    void init(int n){
        this -> N = n;
        this -> l = new vector<pair<int, int>>[N];
    }

    void addEdge(int u, int v, int wt){
        l[u].emplace_back(v, wt);
        l[v].emplace_back(u, wt);
    }

    int PRIMS(){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<bool> vis(N, false);
        pq.push({0, 1});
        int tot_cost = 0;
        while(!pq.empty()){
           auto it = pq.top();
           int node = it.second;
           int cost = it.first;
           pq.pop();

           if(vis[node])continue;
           tot_cost += cost;
           vis[node] = true;
           cout << node << ' ';
           for(auto x : l[node]){
               if(!vis[x.first]){
                   pq.push({x.second, x.first});
               }
           }
        }
        cout << '\n';
        return tot_cost;
    }

}MST;

int main(){
    int n, m;
    cin >> n >> m;
    MST.init(n + 1);
    for(int i = 0; i < m; i++){
        int u, v, wt;
        cin >> u >> v >> wt;
        MST.addEdge(u, v, wt);
    }
    cout << MST.PRIMS() << '\n';
    return 0;
}