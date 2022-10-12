#include <bits/stdc++.h>
using namespace std;

class GP{
public:
    int n = 26;
    vector<pair<int, int>> *g;
   void init(){
        this -> g = new vector<pair<int, int>>[n];
    }

    void AddEdge(int u, int v, int wt){
        g[u].emplace_back(v, wt);
        g[v].emplace_back(u, wt);
    }
    int dijkstra(int src, int dest){
       vector<int> dist(n, INT_MAX);
       set<pair<int, int>> s;
       s.insert({0, src});
       dist[src] = 0;
        while (!s.empty()){
            auto it = s.begin();
            int node = it -> second;
            int cur_dist = it -> first;
            s.erase(it);
            for(auto x : g[node]){
                if(x.second + cur_dist < dist[x.first]){
                   if(s.find({dist[x.first], x.first}) != s.end()){
                       s.erase({dist[x.first], x.first});
                   }
                    dist[x.first ] = x.second + cur_dist;
                    s.insert({dist[x.first], x.first});
                }
            }
        }
        return dist[dest];
   }

}G;

int main(){
    int m;
    cin >> m;
    G.init();
    for(int i = 0; i < m; i++){
        char u, v; int wt;
        cin >> u >> v >> wt;
        G.AddEdge(u - 'A', v - 'A', wt);
    }
    char source, dest;
    cin >> source >> dest;
    cout << G.dijkstra(source - 'A', dest - 'A') << '\n';
    return 0;
}