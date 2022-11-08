#include<bits/stdc++.h>
using namespace std;
#define int long long int

bool valid(int x, int y, int n, int m){
    return x >= 1 and x <= n and y >= 1 and y <= m;
}

int max_gold_mine(vector<vector<int>> &grid, int n, int m, vector<vector<int>> &dp){
    for(int i = 1; i <= n; i++)dp[i][1] = grid[i][1];
    int ans = 0;
    for(int j = 2; j <= m; j++){
        for(int i = 1; i <= n; i++){
            int a = 0, b = 0, c = 0;
            dp[i][j] = grid[i][j];
            if(valid(i - 1, j - 1, n, m)){
                a = dp[i - 1][j - 1];
            }
            if(valid(i, j - 1, n, m)){
                b = dp[i][j - 1];
            }
            if(valid(i + 1, j - 1, n, m)){
                c = dp[i + 1][j - 1];
            }
            dp[i][j] += max({a, b, c});
            if(j == m) ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n + 1, vector<int> (m + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> dp(n + 2, vector<int> (m + 2, 0));
    cout << max_gold_mine(grid, n, m, dp) << '\n';
    return 0;
}
