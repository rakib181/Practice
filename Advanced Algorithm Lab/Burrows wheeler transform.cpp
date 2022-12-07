#include<bits/stdc++.h>
using namespace std;

void radix_sort(vector<pair<pair<int, int>, int>> &a){
    int n = (int) a.size();
    {
        vector<int> cnt(n), pos(n);
        vector<pair<pair<int, int>, int>> new_a(n);
        for(auto x : a){
            cnt[x.first.second]++;
        }
        pos[0] = 0;
        for(int i = 1; i < n; i++){
            pos[i] = pos[i - 1] + cnt[i - 1];
        }
        for(auto x : a){
            int i = x.first.second;
            new_a[pos[i]] = x;
            pos[i]++;
        }
        a = new_a;
    }
    {
        vector<int> cnt(n), pos(n);
        vector<pair<pair<int, int>, int>> new_a(n);
        for(auto x : a){
            cnt[x.first.first]++;
        }
        pos[0] = 0;
        for(int i = 1; i < n; i++){
            pos[i] = pos[i - 1] + cnt[i - 1];
        }
        for(auto x : a){
            int i = x.first.first;
            new_a[pos[i]] = x;
            pos[i]++;
        }
        a = new_a;
    }
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    s += '$';
    int n = (int) s.size();
    vector<int> p(n), c(n);
    {
        vector<pair<char, int>> a(n);
        for(int i = 0; i < n; i++){
            a[i] = {s[i], i};
        }
        sort(a.begin(), a.end());
        for(int i = 0; i < n; i++){
            p[i] = a[i].second;
        }
        c[p[0]] = 0;
        for(int i = 1; i < n; i++){
            if(a[i].first == a[i - 1].first){
                c[p[i]] = c[p[i - 1]];
            }else c[p[i]] = c[p[i - 1]] + 1;
        }
    }
    int k = 0;
    while ((1 << k) < n){
        vector<pair<pair<int, int>, int>> a(n);
        for(int i = 0; i < n; i++){
            a[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
        }
        radix_sort(a);
        for(int i = 0; i < n; i++){
            p[i] = a[i].second;
        }
        c[p[0]] = 0;
        for(int i = 1; i < n; i++){
            if(a[i].first == a[i - 1].first){
                c[p[i]] = c[p[i - 1]];
            }else c[p[i]] = c[p[i - 1]] + 1;
        }
        k++;
    }
    string bwt;
    for(int i = 0; i < n; i++){
        string tmp;
        if(p[i] != 0)tmp = s.substr(p[i], n) + s.substr(0, (p[i] + n) % n);
        else tmp = s.substr(0, n);
        bwt += tmp[n - 1];
    }
    cout << bwt << '\n';
    return 0;
}
