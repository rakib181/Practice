#include <bits/stdc++.h>
using namespace std;

class edge{
public:
    int u, v, wt;
};

class compare{
public:
    bool operator()(const edge x, const edge y){
        return x.wt < y.wt;
    }
}cmp;

class DSU{
public :
    vector<int> Parent;
    vector<int> Rank;

    void init(int n){
        Parent.resize(n);
        Rank.resize(n, 1);
        iota(Parent.begin(), Parent.end(), 0);
    }

    int find(int v){
        if(Parent[v] == v)return v;

        return Parent[v] = find(Parent[v]);
    }

    void m_union(int u, int v){
        u = find(u), v = find(v);
        if(u == v)return;

        if(Rank[u] > Rank[v]){
            Parent[u] = v;
        }else if(Parent[v] > Parent[u]){
            Parent[v] = u;
        }else{
            Parent[v] = u;
            Rank[u]++;
        }
    }
}dsu;

int main(){
    int n, m;
    cin >> n >> m;
    dsu.init(n + 1);
    vector<edge> ar;
    for(int i = 0; i < m; i++){
        int u, v, wt;
        cin >> u >> v >> wt;
        ar.push_back({u, v, wt});
    }
    int ans = 0;
    sort(ar.begin(), ar.end(), cmp);
    for(auto x : ar){
        if(dsu.find(x.u) != dsu.find(x.v)){
            dsu.m_union(x.u, x.v);
            ans += x.wt;
            cout << x.u << ' ' << x.v << ' ' << x.wt << '\n';
        }
    }
    cout << ans << '\n';
    return 0;
}