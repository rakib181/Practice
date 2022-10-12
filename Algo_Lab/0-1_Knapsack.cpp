#include <bits/stdc++.h>
using namespace std;

int knapsack(int idx, int weight, vector<pair<int, int>> &ar, int n, vector<vector<int>> &dp, int w){
    if(idx == n)return 0;
    if(dp[idx][weight] != -1) return dp[idx][weight];
    int ans = 0;
    if(ar[idx].second + weight <= w)ans = max(ans, knapsack(idx + 1, weight + ar[idx].second, ar, n, dp, w) + ar[idx].first);
    ans = max(ans, knapsack(idx + 1, weight, ar, n, dp, w));
    return dp[idx][weight] = ans;
}

int main(){
    int n, w;
    cin >> n >> w;
    vector<pair<int, int>> ar(n);
    for(int i = 0; i < n; i++){
        cin >> ar[i].first >> ar[i].second;
    }
    vector<vector<int>> dp(n + 1, vector<int> (w + 1, -1));
    cout << knapsack(0, 0, ar, n, dp, w) << '\n';
    return 0;
}